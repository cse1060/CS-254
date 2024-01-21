// Pratham Gupta - 220001060
// Question
// Obtain the median element from an unsorted array.
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

// Time Complexicity --> O(n)
// Space Complexicity --> O(1)

vector<ll> Min_Elements(vector<ll> &v)
{
    ll mi1 = INT64_MAX, mi2 = INT64_MAX;
    for (auto it : v)
    {
        if (it < mi1)
        {
            mi2 = mi1;
            mi1 = it;
        }
        else if (it < mi2)
        {
            mi2 = it;
        }
    }
    return {mi1, mi2};
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

        vector<ll> ans = Min_Elements(v);
        cout << "The ans of testcase " << tt << " is ->\n";
        cout << "1st Smallest Element- " << ans[0] << endl;
        cout << "2nd Smallest Element- " << ans[1] << endl;
        cout << endl;
    }
}