# Homework21

## The Problem

From https://accu.org/journals/cvu/cvu36-1:

Homework Challenge 21

First, definitions:

A proper divisor of a number is any number that divides it exactly other than the number itself. <br>
Note that 1 is a proper divisor of all numbers.<br>
An untouchable number is one that is NOT the sum of the proper divisors of any number.<br>
Some examples:<br>
<br>
2 is untouchable<br>
3 is not untouchable because it is the sum of the proper divisors of 4 (1 and 2)<br>
4 is not untouchable because it is the sum of the proper divisors of 9 (1 and 3)<br>
5 is untouchable<br>
6 is not untouchable as it is the sum of its own proper divisors, i.e. it is perfect.<br>
<br>
Task: write a program that will produce all the untouchable numbers less than 1000.

## The Solution

I decided to use "modern" C++20, since we are trying to update ourselves to this at work so I don't know anything more recent.

My environment:
```
mrj@ktulu:~/code/Homework21$ gcc --version
gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
```

My command line:
```
mrj@ktulu:~/code/Homework21$ g++ -std=c++20 hw21.cpp && ./a.out
```

I have tried to use the STL wherever possible - mostly in the form of ranges and algorithms. Why reinvent the wheel?

I started by TDDing the `proper_divisors()` function, and I have left the tests in place to show how simple basic TDD can be, and so that I can add to them when necessary.
Without this function being known to be correct, the whole thing is just building on sand.

After some experimentation it was obvious that you need to calculate a much larger set of touchable numbers than the range you're investigating.
I started by calculating up to 1000, and the list was far more populous than the one in the [Wikipedia article](https://en.wikipedia.org/wiki/Untouchable_number).
As I added more and more the results settled towards the correct answer, and it seemed (empirically) that we needed to calculate 1 million touchable numbers for the first 1000 untouchable to be correct.
After I showed this to my son (currently finishing maths A-levels) he explained why. 
1 million is square, and its divisors therefore include 1 and 1000, which sum to 1001. 
If there are any other divisors they will only add to the sum, making it more than 1001.
We are only looking for untouchables up to 1000, so at this point we can stop looking.
Thinking this way reveals some other optimisations:
<br>
*(more to come!)*
