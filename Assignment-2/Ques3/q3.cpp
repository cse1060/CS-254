// Pratham Gupta - 220001060
// Question
// Use the merging algorithm in Q2 to sort an unsorted array.
//-- Change the input file for the testcases
//---- The Output comes in the output file
//------ The first line in output.in represents the no. of test cases
//--------- The next 2t lines follow
//     ---> The no. of elements in the unsorted array (n)
//     ---> (n) Elements in array A separated by " "(space);

// Time Complexicity --> O(n^2)
// Space Complexicity --> O(1)

// Code starts here
#include <bits/stdc++.h> //Including the header files
#include <cstdio>
using namespace std;
#define ll long long

// Function to merge A and B
void merge(int n, int m, vector<int> &A)
{
    // cout << m << endl;
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

void insertion_sort(int n, vector<int> &A)
{
    for (int i = 1; i < n; i++)
    {
        merge(i + 1, i, A);
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
        ll n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++)
            cin >> A[i];

        insertion_sort(n, A);

        cout << "The merged array of testcase " << tt << " is ->\n";
        for (auto it : A)
            cout << it << " ";
        cout << endl;
    }
}