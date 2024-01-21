// Pratham Gupta - 220001060
// Question
// Obtain the median element from an unsorted array
//-- Change the input file for the testcases
//---- The Output comes in the output file
//------ The first line in output.in represents the no. of test cases
//--------- The next 2t lines follow
//     ---> The no. of elements in array (n)
//     ---> (n) Elements in array separated by " "(space);

// Time Complexicity --> O(n*n)
// Space Complexicity --> O(1)

// Code starts here
#include <bits/stdc++.h> //Including the header files
#include <cstdio>
using namespace std;
#define ll long long

// Function to find the median
double Median(vector<int> &v)
{
    int n = v.size();
    if (n % 2)
        return v[n / 2];
    else
        return (v[n / 2] + v[(n - 1) / 2]) * 1.0 / 2;
}

// Sorting the array
int median(int a, int b, int c)
{
    if ((a <= b && b <= c) || (c <= b && b <= a))
        return b;
    else if ((b <= a && a <= c) || (c <= a && a <= b))
        return a;
    else
        return c;
}

int partition(vector<int> &v, int low, int high)
{
    int pivot = median(v[low], v[(low + high) / 2], v[high]);
    int i = low - 1, j = high + 1;

    while (true)
    {
        i++;
        while (v[i] < pivot)
        {
            i++;
        }
        j--;
        while (v[j] > pivot)
        {
            j--;
        }
        if (i >= j)
            return j;
        else
        {
            swap(v[i], v[j]);
        }
    }
}

void QuickSort(vector<int> &v, int low, int high)
{
    if (low >= high)
        return;

    int pivot = partition(v, low, high);

    QuickSort(v, low, pivot);
    QuickSort(v, pivot + 1, high);
}

int main()
{
    // Taking input from input.in and giving output to output.out
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif

    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        QuickSort(v, 0, n - 1);
        double ans = Median(v);

        cout << "The median of testcase " << tt << " is -> " << ans << endl;
    }
}