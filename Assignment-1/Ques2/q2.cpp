// Pratham Gupta - 220001060
// Question-->
// ****************************************************************************************
// You are given a set of items, each with a weight and a value. Your goal is to determine
// the maximum value that can be obtained by selecting a subset of these items such that the
// total weight does not exceed a given limit.
// ****************************************************************************************
//-- Change the input file for the testcases
//---- The Output comes in the output file
//------ The first line in output.in represents the no. of test cases
//--------- The next 3t lines follow
//     1---> The no. of elements in array (n) and the maximum possible Weight
//     2---> (n) Elements separated by " "(space) representing the weights;
//     3---> (n) Elements separated by " "(space) representing the Values of the corresponding weights;

// Code starts here
#include <bits/stdc++.h> //Including the header files
#include <cstdio>
using namespace std;
#define ll long long

ll N = 1e3; // Constraint of n
ll M = 1e5; // Constraint of max_value

// dp array for the use in function
vector<vector<ll>> dp(N + 10, vector<ll>(M + 10));
// Vectors to store weight and values
vector<int> weight(N + 10), val(N + 10);

ll MaxValue(int n, int w)
{
    if (n <= 0 || w <= 0)
    {
        // Base condition
        return 0;
    }
    if (dp[n][w] != -1)
    {
        // Dp to prevent same recursive calls
        return dp[n][w];
    }
    ll x = MaxValue(n - 1, w); // When the current weight is not included and the max allowed weight is w
    ll y = 0;
    if (weight[n - 1] <= w)
    {
        // Case when if possible , include the current weihght and remaining weight by using others
        y = val[n - 1] + MaxValue(n - 1, w - weight[n - 1]);
    }
    // Taking the max of both the cases
    dp[n][w] = max(x, y);
    return dp[n][w];
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
        int n, maxWt;
        cin >> n >> maxWt;
        for (int i = 0; i < n; i++)
            cin >> weight[i];
        for (int i = 0; i < n; i++)
            cin >> val[i];

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= maxWt; j++)
            {
                dp[i][j] = -1;
            }
        }
        cout << "The max possible value of testcase " << tt << " is -> " << MaxValue(n, maxWt) << endl;
    }
}