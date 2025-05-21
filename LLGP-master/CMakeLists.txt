cmake_minimum_required(VERSION 3.15)
project(LLGP)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define SFML_STATIC to enable static linking in SFML code
add_compile_definitions(SFML_STATIC)

# SFML paths
set(SFML_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/Packages/SFML/include")
set(SFML_LIB_DIR "${CMAKE_SOURCE_DIR}/Packages/SFML/lib")

# Collect all source files
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS Scripts/*.cpp)

# Create executable
add_executable(LLGP ${SOURCES})

# Include SFML headers
target_include_directories(LLGP PRIVATE ${SFML_INCLUDE_DIR})

# Link to SFML library folder
target_link_directories(LLGP PRIVATE ${SFML_LIB_DIR})

# Link against SFML static libraries
target_link_libraries(LLGP PRIVATE
    sfml-system-s
    sfml-window-s
    sfml-graphics-s
    sfml-audio-s
    sfml-network-s
)

# Link necessary system libraries (especially on Windows)
if (WIN32)
    target_link_libraries(LLGP PRIVATE winmm gdi32 opengl32 freetype)
endif()
