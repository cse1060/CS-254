// Pratham Gupta - 220001060
// Question
// Let x1, x2, . . . , xn be a set of integers.
// Give an O(n) divide-and-conquer algorithm to find the largest possible sum of
// a subsequence of consecutive items in the list.
//-- Change the input file for the testcases
//---- The Output comes in the output file
//------ The first line in output.in represents the no. of test cases
//--------- The next 2t lines follow
//     ---> The no. of elements in array (n)
//     ---> (n) Elements in array separated by " "(space);

// Time Complexicity = O(n)
// Space Complexicity = O(1)

// Code starts here
#include <bits/stdc++.h> //Including the header files
#include <cstdio>
using namespace std;
#define ll long long

int ans;

vector<int> MaxSum(vector<int> &v, int left, int right)
{
    if (left == right)
    {
        ans = max(ans, v[left]);
        return {v[left], max(0, v[left]), max(0, v[left])};
    }

    int mid = left + (right - left) / 2;

    vector<int> a = MaxSum(v, left, mid);
    vector<int> b = MaxSum(v, mid + 1, right);

    ans = max(ans, a[2] + b[1]);
    return {
        a[0] + b[0],
        max(a[1], a[0] + b[1]),
        max(b[2], b[0] + a[2])};
}

int main()
{
    // Taking input from input.in and giving output to output.out
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);

    ll t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {
        ll n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        ans = INT_MIN;
        MaxSum(v, 0, n - 1);

        cout << "The max sum of testcase " << tt << " is -> " << ans << endl;
    }
}