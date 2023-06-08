#!/bin/bash
cp src/fibonacci.txt src/build
cd src/build
./main fibonacci.txt
cat src/build/output_file.txt
