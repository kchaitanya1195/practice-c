#!/bin/bash

g++ ds.cpp binary-tree.cpp 
if [[ $? == 0 ]]; then
    ./a.out
fi
