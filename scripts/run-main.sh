#!/bin/bash
cp src/fibonacci.txt src/build
cd src/build
./main fibonacci.txt
cat output_file.txt
