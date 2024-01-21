// Pratham Gupta - 220001060
// Question
// You are given an array A of n elements, where the first m (≤ n) elements are sorted and
// the remaining (n − m) elements are also sorted. However, the array A may not be sorted.
// (a) Write down an in-place merge algorithm to sort A.
//-- Change the input file for the testcases
//---- The Output comes in the output file
//------ The first line in output.in represents the no. of test cases
//--------- The next 2t lines follow
//     ---> The no. of elements in first half of sorted arrayA (n) and the remaining elements (m)
//     ---> (n + m) Elements in array A separated by " "(space);

// Code starts here
#include <bits/stdc++.h> //Including the header files
#include <cstdio>
using namespace std;
#define ll long long

// Time Complexicity --> O((n-m)*n) == O(n^2)
// Space Complexicity --> O(1)

// Function to merge A and B
void merge(int n, int m, vector<int> &A)
{
    for (int i = m; i < n; i++)
    {
        int j = i - 1;
        int temp = A[i];
        while (j >= 0 && A[j] > temp)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = temp;
    }
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
        ll n, m;
        cin >> n >> m;
        vector<int> A(n);
        for (int i = 0; i < n; i++)
            cin >> A[i];

        merge(n, m, A);
        cout << "The merged array of testcase " << tt << " is ->\n";
        for (auto it : A)
            cout << it << " ";
        cout << endl;
    }
}