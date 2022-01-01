#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Window.h"
#include "Shader.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "stb_image.h"



//GLfloat vertices[] = {
//  //vertices                       //color                //tex cord
//  -0.5f, -0.5f   ,  0.75f   ,     1.0f,0.0f,0.0f,    0.0, 0.0,
//   0.5f, -0.5f   ,  0.75f   ,     0.0f,1.0f,0.0f,    1.0, 0.0,
//   0.5f,  0.5f   ,  0.75f   ,     0.0f,0.0f,1.0f,    1.0, 1.0,
//  -0.5f,  0.5f   ,  0.75f   ,     0.0f,1.0f,0.0f,    0.0, 1.0,
//                               
//                               
// // -1.0f, -1.0f   , -0.75f   ,     0.0f,0.0f,1.0f,    0.0, 0.0,
// //  1.0f, -1.0f   , -0.75f   ,     1.0f,0.0f,0.3f,    1.0, 0.0,
// //  1.0f,  1.0f   , -0.75f   ,     0.0f,1.0f,0.0f,    1.0, 1.0,
// // -1.0f,  1.0f   , -0.75f   ,     0.0f,0.0f,1.0f,    0.0, 1.0,
//
//};

float vertices[] = {
    // positions          // colors           // texture coords
     0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
     0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
    -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
};




unsigned int indices[] = {
    0,1,2,
    0,2,3,

    //1,5,6,
    //1,6,2,
    //
    //5,4,7,
    //5,7,6,
    //
    //4,0,3,
    //4,3,6,
    //
    //0,5,4,
    //0,5,1,
    //
    //3,7,6,
    //3,6,2


};


int main()
{
 //   glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
 //   glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
 //   glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
 //   glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    Core::Window& window = Core::Window::getInstanse();
    glewExperimental = GL_TRUE;

    Shader shader("C:/Users/Future/Desktop/PROJECTS/Tyrannosaurus/ASSETS/shader.glsl");
    

    
    unsigned int  VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,32, (GLvoid*)0);
                                                   
    glEnableVertexAttribArray(1);                  
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,32, (GLvoid*)12);

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 32, (GLvoid*)24);



    unsigned int IBO;
    glGenBuffers(1, &IBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &indices, GL_STATIC_DRAW);



    stbi_set_flip_vertically_on_load(1);
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    // set the texture wrapping/filtering options (on the currently bound texture object)

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

    // load and generate the texture
    int width, height, nrChannels;
    unsigned char* data = stbi_load("C:/Users/Future/Desktop/PROJECTS/Tyrannosaurus/Textures/mem.png", &width, &height, &nrChannels, 0);
   
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);









    glBindBuffer(GL_ARRAY_BUFFER, 0); 
    glBindVertexArray(0); 
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    //glBindTexture(GL_TEXTURE_2D, 0);
    


    

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::rotate(model, glm::radians(1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 view = glm::mat4(1.0f);
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -5.0f));
    glm::mat4 projection;
    projection = glm::perspective(glm::radians(65.0f), (float)800 / 800, 0.1f, 10.0f);

    glEnable(GL_DEPTH_TEST);
    while (!glfwWindowShouldClose(window.getGLFWwindow()))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        




        //glActiveTexture(GL_TEXTURE0); // activate the texture unit first before binding texture
        //glBindTexture(GL_TEXTURE_2D, texture);
        shader.Bind();
        glBindVertexArray(VAO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
        //glBindTexture(GL_TEXTURE_2D, textureID);
        
        

       
       shader.SetUniform1i("ourTexture", 0);



       glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
       //glDrawArrays(GL_TRIANGLES,0,36);



       
       glfwPollEvents();
        glfwSwapBuffers(window.getGLFWwindow());
    }
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glfwTerminate();
    return 0;
}

