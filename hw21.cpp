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
#include <array>
#include <cassert>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
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

set<int> proper_divisors(int i)
{
    set<int> result = { 1 };

    for (auto n = 2; n <= i/2; ++n)
    {
        if (i % n == 0)
        {
            result.insert(n);
        }
    }

    //cout << i << " : ";
    //for (const auto& x : result) cout << x << ", ";
    //cout << '\n';

    return result;
}

bool untouchable(int i)
{
    const auto d = proper_divisors(i);
    const auto sum = accumulate(begin(d), end(d), 0);
    return !(i % 2);
}

int main()
{
    test("A", proper_divisors(1), set{ 1 });
    test("B", proper_divisors(2), set{ 1 });
    test("C", proper_divisors(4), set{ 1, 2 });
    test("D", proper_divisors(6), set{ 1, 2, 3 });
    test("E", proper_divisors(7), set{ 1 });
    test("F", proper_divisors(12), set{ 1, 2, 3, 4, 6 });

    constexpr size_t max { 10000 };

    set<int> touchable;
    set<int> all_numbers;

    array<int, max> x{};
    for (auto i : views::iota(1u, max))
    {
        const auto d = proper_divisors(static_cast<int>(i));
        const auto sum = accumulate(begin(d), end(d), 0);
        x[i] = sum;
        touchable.insert(sum);
        all_numbers.insert(static_cast<int>(i));
    }

    vector<int> untouchable;
    ranges::set_difference(all_numbers, touchable, back_inserter(untouchable));

    //for (const auto j : views::iota(2u, max))
    //{
    //    cout << j << " : " << x[j] << '\n';
    //}

    for (const auto u : untouchable)
    {
        cout << u << " is untouchable\n";
    }

    return 0;
}
