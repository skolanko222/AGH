# CMake generated Testfile for 
# Source directory: /home/stud2021/1kolanko/laby/sem3/lab5
# Build directory: /home/stud2021/1kolanko/laby/sem3/lab5/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(Test "_NAME")
set_tests_properties(Test PROPERTIES  _BACKTRACE_TRIPLES "/home/stud2021/1kolanko/laby/sem3/lab5/CMakeLists.txt;13;add_test;/home/stud2021/1kolanko/laby/sem3/lab5/CMakeLists.txt;0;")
add_test(Mem "valgrind" "--leak-check=full" "./_NAME")
set_tests_properties(Mem PROPERTIES  _BACKTRACE_TRIPLES "/home/stud2021/1kolanko/laby/sem3/lab5/CMakeLists.txt;14;add_test;/home/stud2021/1kolanko/laby/sem3/lab5/CMakeLists.txt;0;")
