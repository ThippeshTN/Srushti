set(COMPONENT window)
add_library(${COMPONENT} 
    window.cpp)

target_include_directories(${COMPONENT} PUBLIC include)

find_package(SDL2 CONFIG REQUIRED)

target_link_libraries(${COMPONENT}
    SDL2::SDL2
)
