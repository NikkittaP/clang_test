# CMake version string
cmake_minimum_required(VERSION 3.2.1)
cmake_policy(VERSION 3.4.1)

# Project
project(ClangTest)

# CMake modules
include(cmake/RecurseSubdirs.cmake)

# Fleet project dir varibles
set(CORE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(RESULT_DIR ${CMAKE_SOURCE_DIR}/result)

# Versions
set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_PATCH 1)

# Version message
message(STATUS
    "Configuring ${PROJECT_NAME} ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}(${GIT_REVISION})"
)

# Minimum Qt version
set(QT_REQUIRED_VERSION 5.10.0)

# Find QtCore module
find_package(Qt5 ${QT_REQUIRED_VERSION} CONFIG REQUIRED COMPONENTS Core)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

if (MSVC)
	message(STATUS "Windows build")
	set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
	set(CMAKE_CXX_STANDARD 14)
	add_compile_options(/W0)
	set(CMAKE_C_FLAGS "/EHsc -m64")
	set(CMAKE_CXX_FLAGS "/EHsc -m64")
else()
	message(STATUS "Linux build")
	set(CMAKE_C_FLAGS "-m64")
	set(CMAKE_CXX_FLAGS "-m64")
endif(MSVC)

# Add Qt Creator import path
set(QML_IMPORT_PATH "${QML_IMPORT_DIRS}" CACHE STRING "Qt Creator extra qml import paths")

# Project
add_subdirectory(libs)
add_subdirectory(services)