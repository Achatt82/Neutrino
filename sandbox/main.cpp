#include <glad/glad.h>
#include <glfw/glfw3.h>

#include "logger.h"

int main() {

	Logger logger;

	if (!glfwInit()) {
		logger.log(CRITICAL, "Failed to initialize GLFW");
		return -1;
	}

	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Window", nullptr, nullptr);
	if (!window) {
		logger.log(CRITICAL, "Failed to create GLFW context");
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		logger.log(CRITICAL, "Failed to initialize GLAD");
		glfwDestroyWindow(window);
		glfwTerminate();
		return -1;
	}

	// Main loop
	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.3f, 0.3f, 0.3f, 0.2f);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}