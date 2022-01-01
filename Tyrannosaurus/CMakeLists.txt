# CMakeList.txt : CMake project for Tyrannosaurus, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)



file (GLOB file_c "src/*.cpp")
file (GLOB file_h "src/*.h")


file (GLOB ImGuifile_c "imgui/*.cpp")
file (GLOB ImGuifile_h "imgui/*.h")

file (GLOB STBfile_c "stb/*.cpp")
file (GLOB STBfile_h "stb/*.h")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (${PROJECT_NAME} 

	#"src/Game/main.cpp"
	"${file_c}"
	"${file_h}"
	
	"${ImGuifile_c}"
	"${ImGuifile_h}"

	"${STBfile_c}"
	"${STBfile_h}"


)

# TODO: Добавьте тесты и целевые объекты, если это необходимо.

target_link_libraries(${PROJECT_NAME}
	glfw
	libglew_static

)