/* ANEMONE */

// STD
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
  struct application_data data = {true, 0 /*nullptr*/, 0 /*nullptr*/};

  run(&data);

  return EXIT_SUCCESS;
}
