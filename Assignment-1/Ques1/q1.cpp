// Pratham Gupta - 220001060
// Question
// You are given an array of integers, and your task is to find the maximum possible sum of
// two elements in the array
//-- Change the input file for the testcases
//---- The Output comes in the output file
//------ The first line in output.in represents the no. of test cases
//--------- The next 2t lines follow
//     ---> The no. of elements in array (n)
//     ---> (n) Elements in array separated by " "(space);

// Code starts here
#include <bits/stdc++.h> //Including the header files
#include <cstdio>
using namespace std;
#define ll long long

// Function to find the maximum sum of two numbers in an array
ll MaxSum(vector<ll> &v)
{
    // mx1 is largest and mx2 is the smallest
    ll mx1 = INT64_MIN, mx2 = INT16_MIN;
    for (auto it : v)
    {
        if (it > mx1)
        {
            // it becomes the max and mx1 becomes 2nd max
            mx2 = mx1;
            mx1 = it;
        }
        else if (it > mx2)
        {
            // it becomes second max
            mx2 = it;
        }
    }
    // Max sum of 2 nums is the sum of max and 2nd max nums
    return mx1 + mx2;
}

int main()
{
    // Taking input from input.in and giving output to output.out
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif

    ll t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        cout << "The max sum of testcase " << tt << " is -> " << MaxSum(v) << endl;
    }
}