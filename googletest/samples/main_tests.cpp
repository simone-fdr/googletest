#include <iostream>
#include "sample1.h"

int main()
{
    int x = 6;
    int res = Factorial(x);
    std::cout << "factorial of the number : " << std::endl;
    std::cout << res << std::endl;

    std::cout << "the number is prime?" << std::endl;
    std::cout << IsPrime(x) << std::endl;

    return 0;
}