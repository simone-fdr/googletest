#!/bin/bash
mkdir build
cd build
g++ ../../googletest/src/gtest_main.cc ../../googletest/samples/sample1.cc ../../googletest/samples/sample1_unittest.cc ../../googletest/samples/sample2*.cc ../../googletest/samples/sample3*.cc ../../googletest/samples/sample4*.cc ../../googletest/samples/sample5*.cc ../../googletest/samples/sample6*.cc ../../googletest/samples/sample7*.cc ../../googletest/samples/sample8*.cc -o output1 -lpthread -lgtest 
g++ ../../googletest/samples/sample9_unittest.cc -o output2 -lpthread -lgtest
g++ ../../googletest/samples/sample10_unittest.cc -o output3 -lpthread -lgtest