# CMake generated Testfile for 
# Source directory: /home/skolanko222/AGH/cpp/w/testy/temp copy
# Build directory: /home/skolanko222/AGH/cpp/w/testy/temp copy/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(valgrind "valgrind" "--leak-check=full" "--error-exitcode=1" "--show-leak-kinds=all" "--track-origins=yes" "--verbose" "./out")
set_tests_properties(valgrind PROPERTIES  _BACKTRACE_TRIPLES "/home/skolanko222/AGH/cpp/w/testy/temp copy/CMakeLists.txt;30;add_test;/home/skolanko222/AGH/cpp/w/testy/temp copy/CMakeLists.txt;0;")
