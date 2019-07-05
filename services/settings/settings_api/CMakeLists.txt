# Project
project(settings_api)

# Target
add_library(${PROJECT_NAME} SHARED "")

# Includes
HEADER_DIRECTORIES(INCLUDES "include")
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDES})

# Sources
file(GLOB_RECURSE SOURCES "include/*" "src/*")
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})

# Libraries
target_link_libraries(${PROJECT_NAME} PUBLIC service)