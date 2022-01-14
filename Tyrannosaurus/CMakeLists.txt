# CMakeList.txt : CMake project for Tyrannosaurus, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)



file (GLOB ImGuifile_c "imgui/*.cpp")
file (GLOB ImGuifile_h "imgui/*.h")

file (GLOB Enginefile_c "src/Engine/*.cpp")
file (GLOB Enginefile_h "src/Engine/*.h")

file (GLOB Gamefile_c "src/Game/*.cpp")
file (GLOB Gamefile_h "src/Game/*.h")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (${PROJECT_NAME} 

	#"src/Game/main.cpp"
	"${Gamefile_c}"
	"${Gamefile_h}"
	
	"${ImGuifile_c}"
	"${ImGuifile_h}"

	"${Enginefile_c}"
	"${Enginefile_h}"


)

# TODO: Добавьте тесты и целевые объекты, если это необходимо.

include_directories(&{PROJECT_NAME}  ${CMAKE_CURRENT_SOURCE_DIR}/src/Engine)
include_directories(&{PROJECT_NAME}  ${CMAKE_CURRENT_SOURCE_DIR}/src/Game)

target_link_libraries(${PROJECT_NAME}
	glfw
	libglew_static

)