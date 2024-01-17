/* ANEMONE */

// STD
#include "stdio.h"
#include <stdbool.h>
#include <stdlib.h>
#include <vulkan/vulkan_core.h>
// GLFW
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE

#include "anemoneclib.h"
#include "core.h"

int main() {
  // struct application_data data = {true, 0 /*nullptr*/, 0 /*nullptr*/};

  printf("floppa");
  int *i;
  // vec_alloc(i);
    i = vec_init(i, int);
  printf("test");
  printf("%i", *(i-8));

  // printf("%i", i[0]);
  //  run(&data);

  return EXIT_SUCCESS;
}
