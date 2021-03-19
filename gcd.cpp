/*
Given two non-negative integers a and b, 
we have to find their GCD (greatest common divisor), i.e. the largest number 
which is a divisor of both a and b.

TimeCoplexity: O(logmin(a,b))
*/
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
//LCM of 2 numbers using gcd
int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}
int main()
{
    cout << gcd(12, 10) << endl;
    return 0;
}
