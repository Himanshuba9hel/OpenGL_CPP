#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

struct ShaderProgramSource
{
    std::string VertexSourse;
    std::string FragementSource;
};

static ShaderProgramSource ParseShader(const std::string& filepath)
{
    std::ifstream stream(filepath);

    // Add this check!
    if (!stream.is_open())
    {
        std::cout << "ERROR: Failed to open shader file at: " << filepath << std::endl;
        // Return empty strings safely or handle the error
    }

    enum class ShaderType
    {
        NONE = -1, VERTEX = 0, FRAGMENT = 1
    };

    std::string line;
    std::stringstream ss[2];
    ShaderType type = ShaderType::NONE;

    while(getline(stream, line))
    {
        // Changed nops to npos here
        if(line.find("#shader") != std::string::npos){
            // Changed nops to npos here
            if(line.find("vertex") != std::string::npos)
                // set mode for vertex
                type = ShaderType::VERTEX;
            // Changed nops to npos here
            else if(line.find("fragment") != std::string::npos)
                // set mode for fragment
                type = ShaderType::FRAGMENT;
        }else{
            ss[(int)type] << line << '\n';
        }
    }
    return {ss[0].str(),ss[1].str()};
}

static unsigned int CompileShader(
    unsigned int type,
    const std::string& source)
{
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    // TODO: Error Handling
    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if(result == GL_FALSE){
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = (char*) alloca (length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);
        std::cout << "Failed to compile " <<
            (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << std::endl;
        std::cout << message << std::endl;
        glDeleteShader(id);
        return 0;
    }
    return id;
}

static int CreateShader(
    const std::string& vertexShader,
    const std::string& fragmentShader)
{
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}

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

    float positions[6] = {
        -0.5f, -0.5f,
        0.0f,   0.5f,
        0.5f,  -0.5f,
    };

    unsigned int vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    unsigned int buffer;
    glGenBuffers(1,&buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float)*2, 0);


    ShaderProgramSource source = ParseShader("../../../07_Shader_Files/res/shaders/Basic.shader");
    std::cout<<"VERTEX"<<std::endl;
    std::cout<<source.VertexSourse<<std::endl;
    std::cout<<"FRAGMENT"<<std::endl;
    std::cout<<source.FragementSource<<std::endl;

    unsigned int shader = CreateShader(source.VertexSourse,source.FragementSource);
    glUseProgram(shader);

    /*  Loop until user clones the window   */
    while (!glfwWindowShouldClose(window))
    {
        /*   Render here   */
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        /*   Swap front and back buffer    */
        glfwSwapBuffers(window);

        /*   Pull for and process events    */
        glfwPollEvents();
    }

    glDeleteProgram(shader);

    glfwTerminate();
    return 0;
}
