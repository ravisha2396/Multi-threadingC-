**MULTI-THREADING IN C++**

This project is an implementation of threads in C++.

The program simply sums all numbers from 1 to 500,000,000. The result is 125,000,000,250,000,000. 

A function is defined for the following approaches:

**Approach 1:** Single threaded sum.

**Approach 2:** Multithreaded sum, with a variable number of threads ranging from 2-10. The work is split in numerical order. For example, if you have 2 threads, thread 1 shoudl sum up the first half of the numbers and thread 2 should handle the seocnd half.

**Approach 3:** Balanced multithreaded sum. For this approach, we test with a variable number of threads ranging from 2 to (atleast 10). THe work should be split in numerical order. For example, if we have 2 threads, thread 1 should sum up all even numbers and thread 2 should sum up all the even numbers. With 3 threads, thread 1 should handle 1,4,7,...., thread 2 should handle 2,5,8,...., thread 3 should handle 3,6,9,..... . etc. 

Each approach times the total time taken by thread(s), to execute the program and reports the same in the output.

**Compile and Run Instructions:**

1. Ensure you have g++ in your system, else install using - sudo apt-get install g++.

2. Compile: g++ -std=c++11 -O2 -pthread -o output approach<number>.cpp . In place of <number>, input the approach you wish to try.

3. Run ./output
