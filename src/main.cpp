#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <numeric>
#include <cstdio>
#include <gtest/gtest.h>
#include "../googletest/samples/sample1.h"


std::string matrixFileName;


class Matrix {
    private:
        std::vector<std::vector<int>> data;

    public:
        Matrix(const std::string& filename) {
            std::string line;
            std::ifstream file(filename);
            
            while (std::getline(file, line)) {
                std::vector<int> row;
                int value;
                std::istringstream iss(line);

                while (iss >> value) {
                    row.push_back(value);
                    
                }

                data.push_back(row);
            }
        }

        void print() const {
            for (const auto& row : data) {
                for (int value : row) {
                    std::cout << value << " ";
                }
                std::cout << std::endl;
            }
        }

        int getRows(){
            return data.size();
        }
        int getCols(){
            return  data.at(0).size();
        }
        int get(int i, int j) { return data.at(i).at(j);}
        std::vector<int> getRow(int i) { return data.at(i);}
};


TEST(MatrixTest, IsMatrixFull) {
    Matrix matrix(matrixFileName);
    for (int i = 0; i < matrix.getRows(); i++) {
        for(int j = 0; j < matrix.getCols() && j != i; j++){
            ASSERT_EQ(matrix.getRow(i).size(), matrix.getRow(j).size());
        }
    }
}

TEST(MatrixTest, IsMatrixPrime) {
    Matrix matrix(matrixFileName);
    for (int i = 0; i < matrix.getRows(); i++) {
        for (int j = 0; j < matrix.getCols(); j++) {
            ASSERT_TRUE(IsPrime(matrix.get(i, j)));
        }
    }
}

int main(int argc, char** argv) {
    FILE* f_out = freopen("output_file.txt", "w", stdout);
    if (argc > 1) {
        matrixFileName = argv[1];
        testing::InitGoogleTest(&argc, argv);
        int result =RUN_ALL_TESTS();
        fclose(f_out);
        return result;
    } else {
        std::cerr << "No matrix file provided!" << std::endl;
        return 1;
    }
}
