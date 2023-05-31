#include <iostream>
#include <fstream>
#include <string>
#include "sample1.h"

using namespace std;

int main()
{

    // read from file
    // name of file : input.txt
    ifstream newfile;
    newfile.open('input.txt');
    // read contents here
    newfile.close();

    // perform computations
    int x = 6;
    int res = Factorial(x);
    std::cout << "factorial of the number : " << std::endl;
    std::cout << res << std::endl;

    std::cout << "the number is prime?" << std::endl;
    std::cout << IsPrime(x) << std::endl;

    // write to file
    // name of file : output.txt
    ofstream output_file;
    output_file.open('output.txt');
    output_file << "results:" << std::endl;
    // write reseults here
    output_file.close();

    return 0;
}