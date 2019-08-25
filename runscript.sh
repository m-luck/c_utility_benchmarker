#!/bin/bash
# simple script to build and run the c program
BLOCK_SIZE=$1
# create a file of BLOCK_SIZE bytes 
dd if=/dev/zero of=./output.dat  bs=$BLOCK_SIZE  count=1;
# compile the c script
gcc testscript.c -o testfile
# run the script
./testfile $BLOCK_SIZE
# remove the script after running
rm testfile
# remove the data block file
rm output.dat
# remove the output files
rm temp*.dat
