#ifndef __MAP_H__
#define __MAP_H__

#include <stdio.h>
#include <stdint.h>

#define MACADDRSIZE 6

/* -- Hash functions with macaddr -- */
static inline int
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

static inline int
rmac2key(const uint8_t *macaddr, uint64_t *out_key)
{
  uint64_t new_key = 0;
  const uint8_t *ptr = macaddr;

  if (macaddr == NULL || out_key == NULL)
    return -1;

  for (int i = 0; i < 6; ++ptr, i--) {
    new_key |= (uint64_t)*ptr << (8 * i);
  }

  *out_key = new_key;

  return 0;
}

#endif
