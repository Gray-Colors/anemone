#include <vulkan/vulkan_core.h>

#include "anemoneclib.h"
#include "app.h"
// Internal functions
void initWindow(application_data *data) {
  glfwInit();

  data->application_window = glfwCreateWindow(800, 600, "ANEMONE", 0, 0);

  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
}

void createInstance(application_data *data) {
  VkApplicationInfo appInfo = {};
  appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  appInfo.pApplicationName = "Anemone Triangle";
  appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
  appInfo.pEngineName = "No Engine";
  appInfo.apiVersion = VK_MAKE_VERSION(1, 0, 0);
  appInfo.apiVersion = VK_API_VERSION_1_0;
  appInfo.pNext = 0;

  VkInstanceCreateInfo createInfo = {};
  createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  createInfo.pApplicationInfo = &appInfo;

  // Vulkan is platform agnostic, which means it is not tied to any platform.
  // This means, in turn, that we must use extensions to communicate with the
  // platform, as opposed to any inbuilt features.
  uint32_t glfwExtensionCount = 0;
  const char **glfwExtensions;

  glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

  createInfo.enabledExtensionCount = glfwExtensionCount;
  createInfo.ppEnabledExtensionNames = glfwExtensions;

  createInfo.enabledLayerCount = 0;

  // This is C++ code with a fix for VK_ERROR_INCOMPATIBLE_DRIVER when using
  // MacOS with latest MoltenVK SDK. Remember to translate into C for
  // compatibility later down the line.
  /*
std::vector<const char*> requiredExtensions;

// glfwExtensionCount and glfwExtensions are taken from
glfwGetRequiredInstanceExtensions for(uint32_t i = 0; i < glfwExtensionCount;
i++) { requiredExtensions.emplace_back(glfwExtensions[i]);
}

// Following code adds VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR to
VkInstanceCreateInfo's flags, then adds
VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME to instance enabled extension list
requiredExtensions.emplace_back(VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME);

createInfo.flags |= VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR;

createInfo.enabledExtensionCount = (uint32_t) requiredExtensions.size();
createInfo.ppEnabledExtensionNames = requiredExtensions.data();

if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
throw std::runtime_error("failed to create instance!");
}
*/

  // To get just the extension count, the third (/last) parameter can be left
  // away
  uint32_t extensionCount = 0;
  vkEnumerateInstanceExtensionProperties(0 /*nullptr*/, &extensionCount,
                                         0 /*nullptr*/);
  std::vector<VkExtensionProperties> extensions(extensionCount);

  VkExtensionProperties *extensions;
  VkExtensionProperties t;

  extensions = vec_malloc(8 + (20 * sizeof(VkExtensionProperties))) + 8;
  *(extensions - 4) = 20;
  *(extensions - 8) = 20;
      // vec_init_size(extensions, sizeof(t), extensionCount);

      vec_add(vec_ptr, element);

  VkResult result =
      vkCreateInstance(&createInfo, 0 /*nullptr*/, &(data->instance));
  // TODO: assert result
}

void initVulkan(application_data *data) { createInstance(data); }

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
  initVulkan(data);
  gameLoop(data);
  cleanup(data);
}
