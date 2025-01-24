To compile and run use "make" in project root folder.

If you prefer manual "gcc" then run in the program root:
gcc -std=c99 -o ./build/program src/*.c && ./build/program

Debugging tags:
gcc -std=c99 -Wall -Werror -Wpedantic -o ./build/program src/*.c && ./build/program
