#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <numeric>
#include <cstdio>
#include <gtest/gtest.h>
#include "../googletest/samples/sample1.h"


std::string fileName;

class Fibonacci {
    private:
        std::vector<int> data;

    public:
        Fibonacci(const std::string& filename) {
            std::ifstream fin(filename);

            int element;
            while (fin >> element)
            {
                data.push_back(element);
            }
        }

        void print() const {
            for (int value : data) {
                std::cout << value << " ";
            }
            std::cout << std::endl;
        }

        int getSize(){
            return data.size();
        }

        int get(int i) {
            return data.at(i);
        }
};


TEST(FibonacciTest, IsFibonacci) {
    Fibonacci fib(fileName);
    for (int i = 0; i < fib.getSize() - 2; i++) {
        ASSERT_EQ(fib.get(i + 2), fib.get(i) + fib.get(i + 1));
    }
}

TEST(FibonacciTest, IsPrime) {
    Fibonacci fib(fileName);
    for (int i = 0; i < fib.getSize(); i++) {
        ASSERT_TRUE(IsPrime(fib.get(i)));
    }
}

int main(int argc, char** argv) {
    FILE* f_out = freopen("output_file.txt", "w", stdout);
    if (argc > 1) {
        fileName = argv[1];
        std::cout << fileName << std::endl;
        Fibonacci fibMain(fileName);
        std::cout << fibMain.getSize() << std::endl;
        //std::cout << fibMain.get(0) << " " << fibMain.get(1) << " " << fibMain << fibMain.get(2) << std::endl;
        testing::InitGoogleTest(&argc, argv);
        int result =RUN_ALL_TESTS();
        fclose(f_out);
        return result;
    } else {
        std::cerr << "No sequence file provided!" << std::endl;
        return 1;
    }
}
