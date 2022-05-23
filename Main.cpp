#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <KHR/khrplatform.h>

using namespace std;

//framebuffer size callback function
void resize(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void render(GLFWwindow* window) {

    //insert render code here
}

int main() 
{
    //set default width and height
    int width = 800;
    int height = 600;

    //initialize GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //create a window
    GLFWwindow* window = glfwCreateWindow(width, height, "GreenEngine Alpha 0.0.1_indev1", NULL, NULL);

    cout << "Launched Debug window for GreenEngine Alpha 0.0.1_indev1.";

    //set context as window and initialize GLAD
    glfwMakeContextCurrent(window);
    gladLoadGL();

    //receive framebuffer size callbacks
    glfwSetFramebufferSizeCallback(window, resize);

    //run the window loop
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.0f, 0.0f, 0.1f, 0.0f);
        render(window);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}