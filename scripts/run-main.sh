#!/bin/bash
rm src/build/fibonacci.txt
mv src/fibonacci.txt src/build
cd src/build
./main fibonacci.txt