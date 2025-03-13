#!/usr/bin/env python3

def factorial(n):
    return (1 if n == 1 else n*factorial(n-1))

int = int(input("enter integer greater than 0:\n"))

if int <= 0:
    print("int 0 or less")
else:
    print(factorial(int))
