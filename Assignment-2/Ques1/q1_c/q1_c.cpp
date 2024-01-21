// Pratham Gupta - 220001060
// Question
// Given two sorted arrays of A and B of m and n elements, respectively,
// (c) Construct a sorted array C for A ∩ B.
//-- Change the input file for the testcases
//---- The Output comes in the output file
//------ The first line in output.in represents the no. of test cases
//--------- The next 3t lines follow
//     ---> The no. of elements in arrayA (n) and the no. of elements in array B (m)
//     ---> (n) Elements in array A separated by " "(space);
//     ---> (m) Elements in array M separated by " "(space);

// Time Complexicity --> O(n+m)
// Space Complexicity --> O(n+m)

// Code starts here
#include <bits/stdc++.h> //Including the header files
#include <cstdio>
using namespace std;
#define ll long long

ll n, m;
// Function to merge A and B
vector<int> merge_intersection(vector<int> &A, vector<int> &B)
{
    vector<int> ans;
    int i = 0, j = 0;
    while (i < A.size() && j < B.size())
    {
        if (A[i] == B[j])
            ans.push_back(A[i]);
        if (A[i] <= B[j])
        {
            i++;
            while (i < A.size() && A[i - 1] == A[i])
                i++;
        }
        else
        {
            j++;
            while (j < B.size() && B[j - 1] == B[j])
                j++;
        }
    }
    return ans;
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
        cin >> n >> m;
        vector<int> A(n), B(m);
        for (int i = 0; i < n; i++)
            cin >> A[i];
        for (int i = 0; i < m; i++)
            cin >> B[i];

        vector<int> ans = merge_intersection(A, B);
        cout << "The merged A ∩ B array of testcase " << tt << " is ->\n";
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
}