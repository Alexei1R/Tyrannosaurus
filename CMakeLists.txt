﻿


cmake_minimum_required (VERSION 3.8)

project ("Tyrannosaurus")

# Include sub-projects.
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/glfw/")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/glew/")
add_subdirectory ("Tyrannosaurus")








target_include_directories(${PROJECT_NAME}    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/glfw/include )
target_include_directories(${PROJECT_NAME}    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/glew/include )
target_include_directories(${PROJECT_NAME}    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/glm)
target_include_directories(${PROJECT_NAME}    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/imgui)

