project(oldknights LANGUAGES CXX)

add_executable(${PROJECT_NAME} oldknights.cpp)
target_link_libraries(${PROJECT_NAME} oldknights_lib)
