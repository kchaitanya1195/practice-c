#!/bin/bash

g++ ds.cpp binary-tree.cpp stack.cpp queue.cpp heap.cpp hash-table.cpp trie.cpp
if [[ $? == 0 ]]; then
    ./a.out
fi
