#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#include "dlist.h"
#include "map.h"

#define MAPSIZE 563

typedef struct
{
  dlist_t _;

  uint64_t key;
  void *real_data;
} value_t;

#define GET_VALUE(ptr)  ((value_t *)ptr)

static dlist_t g_map[MAPSIZE];

static pthread_mutex_t maplock = PTHREAD_MUTEX_INITIALIZER;

static inline void map_lock(void)
{
  pthread_mutex_lock(&maplock);
}

static inline void map_unlock(void)
{
  pthread_mutex_unlock(&maplock);
}

/* --- Common section --- */
int
mac2key(const uint8_t *macaddr, uint64_t *out_key)
{
  uint64_t new_key = 0;
  const uint8_t *ptr = macaddr;

  if (macaddr == NULL || out_key == NULL)
    return -1;

  for (int i = 5; i >= 0; ++ptr, i--) {
    new_key |= (uint64_t)*ptr << (8 * i);
  }

  *out_key = new_key;

  return 0;
}

/* --- Net map section --- */
static value_t *
value_new (void)
{
  value_t *new_value;

  new_value = calloc(1, sizeof(value_t));
  if (new_value == NULL)
    return NULL;

  return new_value;
}

void
net_map_init(void)
{
  int i;

  for (i = 0; i < MAPSIZE; i++) {
    dlist_init_head(&g_map[i]);
  }
}

int
net_map_put(const uint64_t key, void *data)
{
  value_t* new_value = NULL;
  size_t index;

  if (data == NULL)
    return -1;

  new_value = value_new();
  if (!new_value)
    return -1;

  new_value->key = key;
  new_value->real_data = data;

  index = key % MAPSIZE;

  map_lock();
  dlist_append(&g_map[index], GET_DLIST(new_value));
  map_unlock();

  return 0;
}

int
net_map_lookup_key(const uint64_t key)
{
  int ret = 0;
  size_t index;

  index = key % MAPSIZE;

  map_lock();
  dlist_foreach_safe (&g_map[index]) {
    value_t *v = GET_VALUE(__ptr);

    if (v->key == key) {
      ret = 1;
      break;
    }
  }
  map_unlock();

  return ret;
}

value_t *
net_map_get_value(const uint64_t key)
{
  void* ret = NULL;
  size_t index;

  index = key % MAPSIZE;

  map_lock();
  dlist_foreach_safe (&g_map[index])
  {
    value_t *v = GET_VALUE(__ptr);
    if (v->key == key) {
      ret = v;
      break;
    }
  }
  map_unlock();

  return ret;
}

void *
net_map_get_data(const value_t *value)
{
  void *ret = NULL;

  if (value) {
    ret = value->real_data;
  }

  return ret;
}

value_t *
net_map_remove(const uint64_t key)
{
  void* ret = NULL;
  size_t index;

  index = key % MAPSIZE;

  map_lock();
  dlist_foreach_safe (&g_map[index])
  {
    value_t *v = GET_VALUE(__ptr);
    if (v->key == key) {
      ret = v;
      break;
    }
  }
  if (ret)
    dlist_remove(GET_DLIST(ret));
  map_unlock();

  return ret;
}
