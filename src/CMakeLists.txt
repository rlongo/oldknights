project(oldknights_lib LANGUAGES CXX)

add_library(${PROJECT_NAME} STATIC
    combatant.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC oldknights_inc)
