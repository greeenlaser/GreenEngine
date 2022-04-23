#include <iostream>
#include <GLFW/glfw3.h>
#include <glad.h>
#include <khrplatform.h>

using namespace std;

//create the actual viewport
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {

    glViewport(0, 0, width, height);
}

//get user keyboard input
void processInput(GLFWwindow* window) {
    //closes the application once ESC was pressed
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

int main(void)
{
    //initialize glfw and check for correct versions and profiles
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //create a window
    GLFWwindow* window = glfwCreateWindow(1280, 720, "GreenEngine 0.1", nullptr, nullptr);
    if (window == nullptr) {
        cout << "Failed to create a GLFW window!";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    //initialize glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        cout << "Failed to initialize GLAD!";
        return -1;
    }

    //very simple render loop which keeps the window open until the user closes it
    while (!glfwWindowShouldClose(window)) {
        //viewport scale updates every time user rescales viewport
        glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

        //process user input
        processInput(window);

        //give a new color to the viewport
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    //closes the viewport and console once the user closes the application
    glfwTerminate();
    return 0;
}