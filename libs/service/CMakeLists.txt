# Project
project(service)

# Target
add_library(${PROJECT_NAME} SHARED "")

# Include
target_include_directories(${PROJECT_NAME} PUBLIC "include")

# Sources
file(GLOB_RECURSE SOURCES "include/*" "src/*")
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})

# Libraries
target_link_libraries(${PROJECT_NAME} PUBLIC Qt5::Core)