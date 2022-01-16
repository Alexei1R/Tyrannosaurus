#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 view2;
uniform mat4 projection;
uniform mat4 trans;
uniform mat4 trans2;

out vec3 ourColor;
out vec2 TexCoord;

void main()
{
    gl_Position =  trans * trans2 * projection * view  * view2 * model * vec4(aPos, 1.0);
    //gl_Position = model * view * projection * vec4(aPos, 1.0);
    //gl_Position = projection * view * model * vec4(aPos, 1.0);
    //gl_Position = vec4(aPos, 1.0);


    ourColor = aColor;
    TexCoord = aTexCoord;
}