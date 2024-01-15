
// STD
#include <stdbool.h>
#include <stdlib.h>

// GLFW
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS

typedef struct application_data {
  bool running; // = true;
  GLFWwindow *application_window;
} application_data;

void run(application_data *data);
