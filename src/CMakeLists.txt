cmake_minimum_required(VERSION 3.10)
project(MatrixVector)

# Locate and include Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add an executable for your main.cpp file
add_executable(exec  ../../googletest/src/gtest_main.cc
../../googletest/samples/sample1.cc ../../googletest/samples/sample1_unittest.cc 
../../googletest/samples/sample2.cc ../../googletest/samples/sample2_unittest.cc 
../../googletest/samples/sample3_unittest.cc 
../../googletest/samples/sample4.cc ../../googletest/samples/sample4_unittest.cc 
../../googletest/samples/sample5_unittest.cc  
../../googletest/samples/sample6_unittest.cc 
../../googletest/samples/sample7_unittest.cc 
../../googletest/samples/sample8_unittest.cc)

add_executable(exec2 ../../googletest/samples/sample9_unittest.cc)
add_executable(exec3 ../../googletest/samples/sample10_unittest.cc)

add_executable(main ../main.cpp ../../googletest/samples/sample1.cc)

# Link the executable with Google Test
target_link_libraries(exec GTest::GTest GTest::Main)
target_link_libraries(exec2 GTest::GTest GTest::Main)
target_link_libraries(exec3 GTest::GTest GTest::Main)
target_link_libraries(main GTest::GTest GTest::Main)

