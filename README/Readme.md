# Advanced-Machine-Learning Homework 2
## Review of DP ------ Dial Problem

**Introduction**

This repository contains homework No.2 during course "Advanced Machine Learning".

Goal of Homework 2 is to review basic Dynamic Programming algorithm.

**Problem Description**

We have a dial as the figure shows. Suppose we dial a phone number (containing only digits 0-9) in the following way using two fingers. 

Initially, we put index figure on 1 and middle finger on 2 (denoted by (1,2)).

If a digit is under either of your finger, it can be dialed.

We can move our hand vertically and horizontally each time, but not rotate. Suppose we are on (4,5) now. We can move to (5,6), (1,2),(7,8) by one movement, and move to (2,3),(8,9) by two movements. 

Given a phone number, a string of digits, what’s the minimum number of movements to dial the number?

Use dynamic programming to solve the problem.

**Input**

The first line is a positive integer m, the number of test cases.

In the following m lines, each line is a string of digits(0-9) to dial. Each line contains less than 10000 characters.

**Output**

M lines, line i is the minimum number of movements to dial the i-th phone number.

**Execution**

g++ dial.cpp -o dial.exe
./dial.exe

**Modules**

+ dial.cpp ------ source code of main DP algorithm

**Performance**

Execution time is limited within 1 second.
I get correct output under sample input.

**GitHub links**

https://github.com/wuxiaoyang/advanced-machine-learning-hm2
