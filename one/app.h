
// STD
#include <stdbool.h>
#include <stdlib.h>
#include <vulkan/vulkan_core.h>

// GLFW
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS

// Struct to contain important, global scope data of the application.
typedef struct application_data {
  bool running; // = true;
  GLFWwindow *application_window;
  VkInstance instance;
} application_data;

// Function for running the application. Calls functions for initialisation,
// game loop, and cleanup.
void run(application_data *data);
