#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Shader.h"
#include <iostream>
#include "stb_image.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <windows.h>

#include  "Texture.h"

#include "window.h"
#include "keyboard.h"
#include "mouse.h"
#include "Camera.h"



//float vertices[] = {
//
//    // positions          // colors           // texture coords
//    0.5f,  0.5f, -0.5f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,
//    0.5f, -0.5f, -0.5f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,
//   -0.5f, -0.5f, -0.5f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,
//   -0.5f,  0.5f, -0.5f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f,
//
//    0.5f,  0.5f, 0.5f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,
//    0.5f, -0.5f, 0.5f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,
//   -0.5f, -0.5f, 0.5f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,
//   -0.5f,  0.5f, 0.5f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f,
//
//
//};
//unsigned int indices[] = {
//    0, 1, 3, // first triangle
//    1, 2, 3,
//
//    4,5,0,
//    5,1,0,
//
//    7,6,4,
//    6,5,4,
//
//    3,2,7,
//    2,6,7,
//
//    1,5,2,
//    5,6,2,
//
//    4,0,7,
//    0,3,7
//
//
//};

void sendval(Camera& camera) {
    GLfloat deltaTime = 0.0f;
    GLfloat lastFrame = 0.0f;
    GLfloat currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;



    double xpos = Mouse::getDX();
    double ypos = Mouse::getDY();

    if (Keyboard::key(GLFW_KEY_W)) {
        camera.ProcessKeyboard(Camera_Movement::FORWARD, deltaTime);
    }
    if (Keyboard::key(GLFW_KEY_S)) {
        camera.ProcessKeyboard(Camera_Movement::BACKWARD, deltaTime);
    }
    if (Keyboard::key(GLFW_KEY_A)) {
        camera.ProcessKeyboard(Camera_Movement::LEFT, deltaTime);
    }
    if (Keyboard::key(GLFW_KEY_D)) {
        camera.ProcessKeyboard(Camera_Movement::RIGHT, deltaTime);
    }


    camera.ProcessMouseMovement(xpos, ypos);

}

int main()
{

    CoreNative::Window& window = CoreNative::Window::getInstanse();


    Shader shader("C:/Users/alexe/OneDrive/Desktop/PROJECTS/Tyrannosaurus/Tyrannosaurus/ASSETS/vs.glsl", "C:/Users/alexe/OneDrive/Desktop/PROJECTS/Tyrannosaurus/Tyrannosaurus/ASSETS/fs.glsl");
    shader.Bind();


    Texture tex("C:/Users/alexe/OneDrive/Desktop/PROJECTS/Tyrannosaurus/Tyrannosaurus/Textures/cat.gif");
    tex.Bind(0);
    shader.SetUniform1i("ourTexture", 0);
    

    Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));

    //
    /*unsigned int VBO, VAO, IBO;
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
    glBindVertexArray(0);*/

    //
    GLfloat vertices[] = {
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    };
   
    GLuint VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    // TexCoord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0); // Unbind VAO




    





    glm::mat4 model = glm::mat4(1.0f);
    model = glm::rotate(model, glm::radians(1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 view = glm::mat4(1.0f);
    //view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
    //view = glm::lookAt(glm::vec3(0.0, 0.0, 3.0), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));
    //view = cam.getViewMatrix();
    view = camera.GetViewMatrix();
    
    glm::mat4 projection;
    projection = glm::perspective(glm::radians(65.0f), (float)800 / 800, 0.1f, 1000.0f);
    
    //trans * projection * view  * model

    shader.Bind();
    shader.SetUniformMatrix4f("view", glm::value_ptr(view), 1);
    shader.SetUniformMatrix4f("projection", glm::value_ptr(projection), 1);


    
    




    glfwSetInputMode(window.getGLFWwindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    int width, height;
    glClearColor(0.3, 0.5, 0.4,1.0);
    glEnable(GL_DEPTH_TEST);
    glfwMaximizeWindow(window.getGLFWwindow());
    while (!glfwWindowShouldClose(window.getGLFWwindow()))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glfwGetWindowSize(window.getGLFWwindow(), &width, &height);
        glViewport(0,0,width,height);
        if (Keyboard::key(GLFW_KEY_Q)) {
            glfwSetWindowShouldClose(window.getGLFWwindow(), GLFW_TRUE);
        }
        sendval(camera);


        

        


        shader.Bind();
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

        view = camera.GetViewMatrix();
        //model = glm::rotate(model, (float)glfwGetTime() * glm::radians(0.05f) , glm::vec3(0.0f, 1.0f, 0.0f));

        shader.SetUniformMatrix4f("model", glm::value_ptr(model), 1);
        shader.SetUniformMatrix4f("view", glm::value_ptr(view), 1);
        glDrawArrays(GL_TRIANGLES, 0, 36);

        
        
        
        
        
        //glDrawElements(GL_TRIANGLES,36,GL_UNSIGNED_INT,nullptr);
        


        glfwSwapBuffers(window.getGLFWwindow());
        glfwPollEvents();
        Sleep(16);
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    //glDeleteBuffers(1, &IBO);

    return 0;
}



