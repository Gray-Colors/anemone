#include <cstdlib>
// #include <exception>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>

// #include <iostream>
const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;
class ApplicationRunner {
public:
  void run() {
    initWindow();
    initVulkan();
    gameLoop();
    cleanup();
  }

private:
  bool should_run = -true;
  GLFWwindow *application_window;

  void initWindow() {
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    application_window =
        glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
  }
  void initVulkan() {}

  void gameLoop() {
    while (should_run) {
      glfwPollEvents();
    }
  }

  void cleanup() {
    glfwDestroyWindow(application_window);
    glfwTerminate();
  }
};

int main() {
  ApplicationRunner app;

  app.run();

  return EXIT_SUCCESS;
}
/*
glfwInit();

glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
GLFWwindow* window = glfwCreateWindow(800, 600, "Vulkan window", nullptr,
nullptr);

uint32_t extensionCount = 0;
vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

std::cout << extensionCount << " extensions supported\n";

glm::mat4 matrix;
glm::vec4 vec;
auto test = matrix * vec;

while(!glfwWindowShouldClose(window)) glfwPollEvents();

glfwDestroyWindow(window);
glfwTerminate();
//return EXIT_SUCCESS;
}
*/
