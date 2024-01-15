/* ANEMONE */

// STD
#include <stdbool.h>
#include <stdlib.h>

// GLFW
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE

#include "app.h"


int main() {
  struct application_data data;

  run(&data);

  return EXIT_SUCCESS;
}
