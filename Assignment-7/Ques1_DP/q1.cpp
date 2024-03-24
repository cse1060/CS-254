// Pratham Gupta - 220001060
// Question-->
// ****************************************************************************************
// You are given a set of items, each with a weight and a value. You need to determine which
// items to include in the collection so that the total weight is less than or equal to a given
// limit while maximizing the total cost.
// ****************************************************************************************
//-- Change the input file for the testcases
//---- The Output comes in the output file
//------ The first line in output.in represents the no. of test cases
//     1---> The number of elements n in the array and the max allowed weight
//     2---> The weights w[i]
//     3---> The values v[i]

// Code starts here
#include <bits/stdc++.h> //Including the header files
#include <cstdio>
using namespace std;
#define ll long long

int greedy_ans(vector<int> &w, vector<int> &v, int n, int W)
{
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++)
    {
        a.push_back({w[i], v[i]});
    }
    sort(a.begin(), a.end(), [](pair<int, int> x, pair<int, int> y)
         { return (x.first * 1.0 / x.second) < (y.first * 1.0 / y.second); });
    int ans = 0;
    for (auto it : a)
    {
        if (it.first <= W)
        {
            W -= it.first;
            ans += it.second;
        }
    }
    return ans;
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

        int n, W;
        cin >> n >> W;
        vector<int> weight(n), value(n);
        for (int i = 0; i < n; i++)
            cin >> weight[i];
        for (int i = 0; i < n; i++)
            cin >> value[i];
        int ans = greedy_ans(weight, value, n, W);
        cout << "the max value possible by greedy approach in testcase " << tt << " is -> " << ans << endl;
        cout << endl;
    }
}