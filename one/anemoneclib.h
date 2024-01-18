// This module contains some standard functionality for the engine written in C
// (for example: dynamic arrays).

// Vector library
// #ifndef ANEMONE_VECTOR
// #define ANEMONE_VECTOR

// These definitions can be used to override the standard functions used in this
// file.
#include <stdint.h>
#ifndef vec_redef_free
#include <stdlib.h>
#define vec_free free
#endif

#ifndef vec_redef_malloc
#include <stdlib.h>
#define vec_malloc malloc
#endif

#ifndef vec_redef_calloc
#include <stdlib.h>
#define vec_calloc calloc
#endif

#ifndef vec_redef_realloc
#include <stdlib.h>
#define vec_realloc realloc
#endif

#ifndef vec_redef_assert
#include <assert.h>
#define vec_assert assert
#endif

#ifndef vec_redef_memcpy
#include <string.h>
#define vec_memcpy memcpy
#endif

#ifndef vec_redef_memmove
#include <string.h>
#define vec_memmove memmove
#endif

// typedef void (*cvector_elem_destructor_t)(void *elem);

typedef struct vec_data {
  size_t size;
  size_t capacity;
  // cvector_elem_destructor_t elem_destructor;
} vec_data;

#define vec_init(ptr, type_size /*previously type_t, but some errors there*/)  \
  (void *)vec_malloc(8 /*reserved for pointer for vec_data*/ +                 \
                     (20 * type_size /*sizeof(type_t)*/)) +                    \
      8;                                                                       \
  *(ptr - 4) = 20;                                                             \
  *(ptr - 8) = 20

#define vec_init_size(ptr, type_size /*type_t*/, size)                         \
  (void *)vec_malloc(8 /*reserved for pointer for vec_data*/ +                 \
                     (size * type_size /*sizeof(type_t)*/)) +                  \
      8;                                                                       \
  *(ptr - 4) = size;                                                           \
  *(ptr - 8) = size

// consider moving the code in the if into a function
#define vec_add(vec_ptr, element)                                              \
  if (*(vec_ptr - 8)) == 0) {                                                  \
      *(vec_ptr - 8) = *(vec_ptr - 4);                                         \
      *(vec_ptr - 4) *= 2;                                                     \
      vec_realloc(vec_ptr, *(vec_ptr - 4) * sizeof(element) + 8);              \
      vec_ptr += 8;                                                            \
    }                                                                          \
  vec_ptr[*(vec_ptr - 4) - *(vec_ptr - 8)--] =                                 \
      element; // If the compiler isn't dumb, replace "--" with a new line
               // containing

// With this code, popping from an "empty" vec will will increase capacity
// beyond size. This 'should' cause a segfault, but the first 8 bytes under the
// array are used to store its size and capacity, so as long as (size -
// capacity)*sizeof(type) < -8 bytes, you'll just get some really weird values
#define vec_pop(vec_ptr) vec_ptr[*(vec_ptr - 4) - *(vec_ptr - 8)++]

// #define vec_shrink()

#define free_vec(vec_ptr) vec_free(vec_ptr)
