#!/bin/sh
clear && cd build &&  echo "----------Running cmake..." && cmake .. && echo "----------Running make..." && make && echo "----------Running test program..." && ./greet_test 
