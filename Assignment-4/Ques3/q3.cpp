// Pratham Gupta - 220001060
// Question-->
// ****************************************************************************************
// Given an integer array nums and an integer k, return the k
// th largest element in the array
// ****************************************************************************************
//-- Change the input file for the testcases
//---- The Output comes in the output file
//------ The first line in output.in represents the no. of test cases
//--------- The next 2t lines follow
//     1---> The no. of elements in vector v (n) ant the value of k => (k th largest element)
//     2---> (n) Elements separated by " "(space) representing the elements in v

// Time Complexity  -> O(n *log(n))
// Space Complexity -> O(k)

// Code starts here
#include <bits/stdc++.h> //Including the header files
#include <cstdio>
using namespace std;
#define ll long long

int Kth_largest(vector<int> &v, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(v[i]);
    }
    for (int i = k; i < v.size(); i++)
    {
        if (pq.top() < v[i])
        {
            pq.pop();
            pq.push(v[i]);
        }
    }
    return pq.top();
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
        ll n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        ll ans = Kth_largest(v, k);

        cout << "The " << k << " largest element of testcase " << tt << " is -> " << ans << endl;
    }
}