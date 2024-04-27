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

#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

using namespace std;

template<typename T>
void test(string_view test_name, const T& a, const T& b)
{
    cout <<  "Test " << test_name;
    if (a == b)
        cout << " passed\n";
    else
        cerr << " FAILED!\n";
}

set<int> proper_divisors(int i)
{
    set<int> result = { 1 };

    for (auto n = 2; n <= sqrt(i); ++n)
    {
        if (i % n == 0)
        {
            result.insert(n);
            result.insert(i/n);
        }
    }

    return result;
}

set<int> integers_up_to(int max)
{
    set<int> numbers;
    ranges::for_each(views::iota(1, max), [&](auto n){ numbers.insert(n); });
    return numbers;
}

int touchable(int i)
{
    const auto d = proper_divisors(i);
    return accumulate(begin(d), end(d), 0);
}

vector<int> untouchables_up_to(int max)
{
    set<int> touchables;

    // For each prime (from 2), check up to max x p
    // <too hard!>

    // Check all squares up to max^2
    ranges::for_each(views::iota(1, max), [&](auto n){ touchables.insert(touchable(n * n)); });

    // Above 250,000 the only way the sum of divisors can be less than 1000 is if its a square number (handled above) or prime.
    // If there are more than 2 divisors, they will sum to more than 1000.
    // e.g. 249,999 has divisors 1, 499, 501 (at least) which sum to 1001.
    ranges::for_each(views::iota(1, (max * max) / 4), [&](auto n){ touchables.insert(touchable(n)); });

    const auto all_numbers = integers_up_to(max);
    vector<int> untouchables;
    ranges::set_difference(all_numbers, touchables, back_inserter(untouchables));
    return untouchables;
}

int main()
{
    test("A", proper_divisors(1), set{ 1 });
    test("B", proper_divisors(2), set{ 1 });
    test("C", proper_divisors(4), set{ 1, 2 });
    test("D", proper_divisors(6), set{ 1, 2, 3 });
    test("E", proper_divisors(7), set{ 1 });
    test("F", proper_divisors(9), set{ 1, 3 });
    test("G", proper_divisors(12), set{ 1, 2, 3, 4, 6 });

    const auto untouchables = untouchables_up_to(1000);

    test("X", untouchables, vector{
        2, 5, 52, 88, 96,
        120, 124, 146, 162, 188,
        206, 210, 216, 238, 246, 248, 262, 268, 276, 288, 290, 292,
        304, 306, 322, 324, 326, 336, 342, 372,
        406, 408, 426, 430, 448, 472, 474, 498,
        516, 518, 520, 530, 540, 552, 556, 562, 576, 584,
        612, 624, 626, 628, 658, 668, 670,
        708, 714, 718, 726, 732, 738, 748, 750, 756, 766, 768, 782, 784, 792,
        802, 804, 818, 836, 848, 852, 872, 892, 894, 896, 898,
        902, 926, 934, 936, 964, 966, 976, 982, 996
     });

    cout << "Untouchable : ";
    ranges::for_each(untouchables, [&](auto u){ cout << u << ", "; });
    cout << '\n';

    return 0;
}
