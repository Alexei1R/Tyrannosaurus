#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Shader.h"
#include <iostream>
#include "stb_image.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include  "Texture.h"

#include "window.h"
#include "event.h"

float vertices[] = {

    // positions          // colors           // texture coords
    0.5f,  0.5f, -0.5f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,
    0.5f, -0.5f, -0.5f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,
   -0.5f, -0.5f, -0.5f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,
   -0.5f,  0.5f, -0.5f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f,

    0.5f,  0.5f, 0.5f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,
    0.5f, -0.5f, 0.5f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,
   -0.5f, -0.5f, 0.5f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,
   -0.5f,  0.5f, 0.5f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f,


};
unsigned int indices[] = {
    0, 1, 3, // first triangle
    1, 2, 3,

    4,5,0,
    5,1,0,

    7,6,4,
    6,5,4,

    3,2,7,
    2,6,7,

    1,5,2,
    5,6,2,

    4,0,7,
    0,3,7


};



int main()
{

    CoreNative::Window& window = CoreNative::Window::getInstanse();


    Shader shader("C:/Users/alexe/OneDrive/Desktop/PROJECTS/Tyrannosaurus/Tyrannosaurus/ASSETS/vs.glsl", "C:/Users/alexe/OneDrive/Desktop/PROJECTS/Tyrannosaurus/Tyrannosaurus/ASSETS/fs.glsl");
    shader.Bind();


    Texture tex("C:/Users/alexe/OneDrive/Desktop/PROJECTS/Tyrannosaurus/Tyrannosaurus/Textures/cat.gif");
    tex.Bind(0);
    shader.SetUniform1i("ourTexture", 0);

   
    
    
    window.setfnCallback([](CoreNative::Event& e)
        {
            
            EventValue val = e.format();
            if (e.getType() == CoreNative::Event::EventType::KEY_PRESSED_EVENT)
            {
                //std::cout << (char)val.key << std::endl;;
                std::cout << (char)val.key << std::endl;
                if ((int)val.key == GLFW_KEY_SPACE) {
                    std::cout << "press space" << std::endl;
                }
            }
            

        });

    

     
    




    unsigned int VBO, VAO, IBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &IBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 32, (GLvoid*)0);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 32, (GLvoid*)12);

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 32, (GLvoid*)24);



    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);





    glm::mat4 model = glm::mat4(1.0f);
    model = glm::rotate(model, glm::radians(1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 view = glm::mat4(1.0f);
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
    glm::mat4 projection;
    projection = glm::perspective(glm::radians(65.0f), (float)800 / 800, 0.1f, 10.0f);
    
    //trans * projection * view  * model

    shader.Bind();
    shader.SetUniformMatrix4f("view", glm::value_ptr(view), 1);
    shader.SetUniformMatrix4f("projection", glm::value_ptr(projection), 1);


    
    








    glClearColor(0.3, 0.5, 0.4,1.0);
    glEnable(GL_DEPTH_TEST);
    while (!glfwWindowShouldClose(window.getGLFWwindow()))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



        shader.Bind();
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

        shader.SetUniformMatrix4f("model", glm::value_ptr(model), 1);
        

        model = glm::rotate(model, (float)glfwGetTime() * glm::radians(0.05f) , glm::vec3(0.5f, 1.0f, 0.0f));

        
        glDrawElements(GL_TRIANGLES,36,GL_UNSIGNED_INT,nullptr);




        glfwSwapBuffers(window.getGLFWwindow());
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &IBO);

    return 0;
}






