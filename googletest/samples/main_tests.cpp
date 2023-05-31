#include <iostream>
#include <fstream>
#include <string>
#include "sample1.h"
#include "gtest/gtest.h"
using namespace std;

int main()
{

    // read from file
    // name of file : input.txt
    //ifstream newfile;
    //newfile.open('input.txt');
    // read contents here
    //newfile.close();



    // perform computations
    int x = 6;

    std::cout << "Input number: " << std::endl << x << std::endl;

    int res = Factorial(x);
    std::cout << "Factorial of the number: " << std::endl << res << std::endl;

    bool isPrime = IsPrime(x);
    std::cout << "Is the number prime?" << std::endl << isPrime << std::endl;

    // write to file
    // name of file : output.txt
    //ofstream output_file;
    //output_file.open('output.txt');
    //output_file << "results:" << std::endl;
    // write reseults here
    //output_file.close();

    TEST(FactorialTest, Negative) {
        EXPECT_EQ(1, Factorial(-5));
        EXPECT_EQ(1, Factorial(-1));
        EXPECT_GT(Factorial(-10), 0);
    }

    return 0;
}