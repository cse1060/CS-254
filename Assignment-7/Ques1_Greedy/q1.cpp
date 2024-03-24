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

int dp_ans(vector<int> &w, vector<int> &v, int n, int W)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= W; j++)
        {
            if (w[i - 1] <= j)
            {
                dp[i][j] = max(v[i - 1] + dp[i - 1][j - w[i - 1]], dp[i - 1][j]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    return dp[n][W];
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
        int ans = dp_ans(weight, value, n, W);
        cout << "the max value possible by greedy approach in testcase " << tt << " is -> " << ans << endl;
        cout << endl;
    }
}