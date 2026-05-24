#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window,
                               int width,
                               int height)
{
    glViewport(0, 0, width, height);
}

int main()
{
    // Initialize GLFW
    glfwInit();

    // OpenGL version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

    // Modern OpenGL
    glfwWindowHint(GLFW_OPENGL_PROFILE,
                   GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window =
        glfwCreateWindow(1280,
                         720,
                         "Modern OpenGL",
                         nullptr,
                         nullptr);

    if (!window)
    {
        std::cout << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader(
            (GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD\n";
        return -1;
    }

    std::cout << "Renderer: "
              << glGetString(GL_RENDERER)
              << std::endl;

    std::cout << "OpenGL version: "
              << glGetString(GL_VERSION)
              << std::endl;

    glViewport(0, 0, 1280, 720);

    glfwSetFramebufferSizeCallback(
        window,
        framebuffer_size_callback);

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.1f,
                     0.2f,
                     0.3f,
                     1.0f);

        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}
