#include "app.h"

// Internal functions
void initWindow(application_data *data) {
  glfwInit();

  data->application_window = glfwCreateWindow(800, 600, "ANEMONE", 0, 0);

  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
}

void initVulkan() {}

void gameLoop(application_data *data) {
  while (data->running) {
    glfwPollEvents();
  }
}

void cleanup(application_data *data) {
  glfwDestroyWindow(data->application_window);
  glfwTerminate();
}


// Module API
void run(application_data *data) {
  initWindow(data);
  initVulkan();
  gameLoop(data);
  cleanup(data);
} 
