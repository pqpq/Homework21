// ACCU Homework Challenge 21.
//
// https://accu.org/journals/cvu/cvu36-1
// 
// First, definitions:
// 
// A proper divisor of a number is any number that divides it exactly other than the number itself.
// Note that 1 is a proper divisor of all numbers.
// An untouchable number is one that is NOT the sum of the proper divisors of any number.
// Some examples:
// 2 is untouchable 
// 3 is not untouchable because it is the sum of the proper divisors of 4 (1 and 2) 
// 4 is not untouchable because it is the sum of the proper divisors of 9 (1 and 3)
// 5 is untouchable
// 6 is not untouchable as it is the sum of its own proper divisors, i.e. it is perfect.
// 
// Task: Write a program that will produce all the untouchable numbers less than 1000.


#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void test(string_view test, const T&&a, const T&&b)
{
    if (a == b)
        cout <<  "Test " << test << " passed\n";
    else
        cerr << "Test " << test << " FAILED!\n";
}

vector<int> divisors(int i)
{
    vector<int> result = { 1 };
    if (i > 1) result.push_back(i);
    return result;
}


int main()
{
    test("A", divisors(1), vector{ 1 });
    test("B", divisors(2), vector{ 1, 2 });
    test("C", divisors(4), vector{ 1, 2, 4 });
    return 0;
}
