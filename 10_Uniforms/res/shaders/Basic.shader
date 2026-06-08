#shader vertex
#version 460 core

layout(location = 0) in vec4 position;

void main()
{
   gl_Position = position;
};


#shader fragment
#version 460 core

layout(location = 0) out vec4 color;

uniform vec4 u_Color; /* Uniform Variable */

void main()
{
   // color = vec4(0.2, 0.3, 0.8, 1.0); /* Shader Value */
   color = u_Color;  /* Get value from uniform */
};
