# CMake generated Testfile for 
# Source directory: /root/AGH/cpp/sem4/lab9_cz
# Build directory: /root/AGH/cpp/sem4/lab9_cz/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(valgrind "valgrind" "--leak-check=full" "--error-exitcode=1" "--show-leak-kinds=all" "--track-origins=yes" "--verbose" "./out")
set_tests_properties(valgrind PROPERTIES  _BACKTRACE_TRIPLES "/root/AGH/cpp/sem4/lab9_cz/CMakeLists.txt;30;add_test;/root/AGH/cpp/sem4/lab9_cz/CMakeLists.txt;0;")
