// Pratham Gupta - 220001060
// Question-->
// ****************************************************************************************
// Given an array of integers A[ ], if i < j and A[i] > A[j] then the pair (i, j) is
// called the inversion of an array A[ ]. Write a program to find the total counts
// of inversion in an array A[ ].
// ****************************************************************************************
//-- Change the input file for the testcases
//---- The Output comes in the output file
//------ The first line in output.in represents the no. of test cases
//--------- The next 2t lines follow
//     1---> The no. of elements in array (n)
//     2---> (n) Elements separated by " "(space) representing the elements

// Time Complexity  -> O(n *log(n))
// Space Complexity -> O(n)

// Code starts here
#include <bits/stdc++.h> //Including the header files
#include <cstdio>
using namespace std;
#define ll long long

int merge_inv(int s, int mid, int e, vector<int> &v)
{
    vector<int> a, b;
    for (int i = s; i <= mid; i++)
    {
        a.push_back(v[i]);
    }
    for (int i = mid + 1; i <= e; i++)
    {
        b.push_back(v[i]);
    }
    int n = a.size(), m = b.size();
    int i = 0, j = 0, k = s;

    int inv = 0;
    while (i < n && j < m)
    {
        if (a[i] <= b[j])
        {
            v[k++] = a[i++];
        }
        else
        {
            inv += n - i;
            v[k++] = b[j++];
        }
    }
    while (i < n)
    {
        v[k++] = a[i++];
    }
    while (j < m)
    {
        v[k++] = b[j++];
    }
    return inv;
}

int countInv(int s, int e, vector<int> &v)
{
    if (s == e)
    {
        return 0;
    }
    int mid = (s + e) / 2;
    int res = countInv(s, mid, v) + countInv(mid + 1, e, v);
    res += merge_inv(s, mid, e, v);
    return res;
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
        // ll ans = 0;
        ll ans = countInv(0, n - 1, v);
        cout << "the number of inversions in testcase " << tt << " is -> " << ans << endl;
    }
}