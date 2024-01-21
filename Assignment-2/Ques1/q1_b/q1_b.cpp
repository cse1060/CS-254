// Pratham Gupta - 220001060
// Question
// Given two sorted arrays of A and B of m and n elements, respectively,
// (b) Construct a sorted array C for A ∪ B.
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
vector<int> merge_union(vector<int> &A, vector<int> &B)
{
    vector<int> ans;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (A[i] < B[j])
        {
            ans.push_back(A[i]);
            i++;
            while (i < n && A[i - 1] == A[i])
                i++;
        }
        else if (A[i] > B[j])
        {
            ans.push_back(B[j]);
            j++;
            while (j < m && B[j - 1] == B[j])
                j++;
        }
        else
        {
            ans.push_back(A[i]);
            i++, j++;
            while (i < n && A[i - 1] == A[i])
                i++;
            while (j < m && B[j - 1] == B[j])
                j++;
        }
    }
    while (i < n)
    {
        ans.push_back(A[i]), i++;
        while (i < n && A[i - 1] == A[i])
            i++;
    }
    while (j < m)
    {
        ans.push_back(B[j]), j++;
        while (j < m && B[j - 1] == B[j])
            j++;
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

        vector<int> ans = merge_union(A, B);
        cout << "The merged AUB array of testcase " << tt << " is ->\n";
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
}