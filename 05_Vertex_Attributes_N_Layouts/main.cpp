#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main(void)
{
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Create OpenGL context FIRST
    glfwMakeContextCurrent(window);

    // Required for modern OpenGL
    glewExperimental = GL_TRUE;

    // THEN initialize GLEW
    if (glewInit() != GLEW_OK)
    {
        std::cout << "GLEW Error!" << std::endl;
        return -1;
    }

    std::cout << glGetString(GL_VERSION) << std::endl;

    /*
    float positions[9] = {
        -0.5f, -0.5f, 0.0f, // <-- 3rd Value is testuxe value or additional value
        0.0f,   0.5f, 0.0f, // <-- 3rd Value is testuxe value or additional value
        0.5f,  -0.5f, 0.0f  // <-- 3rd Value is testuxe value or additional value
    };
    unsigned int buffer;
    glGenBuffers(1,&buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), positions, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float)*2, (const void*)8);
    */


    float positions[6] = {
        -0.5f, -0.5f,
        0.0f,   0.5f,
        0.5f,  -0.5f,
    };
    unsigned int buffer;
    glGenBuffers(1,&buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float)*2, 0);


    // If it gives an output it depends over your GPU

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);
        //glDrawElements();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
