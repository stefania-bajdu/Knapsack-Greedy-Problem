#!/bin/bash

# Nume executabil
EXEC_NAME = greedy

    make
    ./$EXEC_NAME $1 $2
    diff --brief $2 $3 >/dev/null
    if [ $? -eq 1 ]
    then
        printf "Test FAILED\n"
    else 
        printf "Test PASSED\n"
    fi
    