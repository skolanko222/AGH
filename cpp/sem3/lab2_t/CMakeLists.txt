cmake_minimum_required(VERSION 2.8)

project(_NAME)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB SRC_FILES *.cpp)
file(GLOB HDR_FILES *.hpp *.h)
add_executable(${PROJECT_NAME}.exe ${SRC_FILES} ${HDT_FILES})

include(CTest)
enable_testing()
add_test(NAME Test COMMAND ${PROJECT_NAME})
add_test(NAME Mem COMMAND valgrind --leak-check=full ./${PROJECT_NAME})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)