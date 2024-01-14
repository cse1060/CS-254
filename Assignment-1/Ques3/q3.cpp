// Pratham Gupta - 220001060
// Question-->
// ****************************************************************************************
// The Traveling Salesman Problem is a classic optimization problem where a salesman is
// given a list of cities and the distances between each pair of cities. The task is to find the
// shortest possible route that visits each city exactly once and returns to the original city.
// ****************************************************************************************
//-- Change the input file for the testcases
//---- The Output comes in the output file
//------ The first line in output.in represents the no. of test cases
//--------- For each test case
//     1---> The first line conatins no. of nodes in the graph
//     2---> A n*n matrix representing the adjancecy matrix of the graph

// Time Comprexity O((n^2)*2^n)

// Code starts here
#include <bits/stdc++.h> //Including the header files
#include <cstdio>
using namespace std;
#define ll long long

// Function to calculate the shortest required path(hemiltonian cycle with least value)
int ShortestPath(int curr, int x, vector<int> dp, vector<vector<int>> &g)
{
    // the ith unset bit represents that the ith node has been visited
    if (x == 1)
        return g[curr][0]; // When the cycle completes

    if (dp[x] != -1)
        return dp[x]; // Dynamic programming prevents the calling of similar patterns again

    dp[x] = INT_MAX; // Making the dp[x] int max to make taking min feasible

    // Analysing all the possible cases from current node to unvisited nodes
    for (int i = 1; i < g[curr].size(); i++)
    {
        if (i == curr || (x & (1 << i)) == 0)
            continue;
        dp[x] = min(dp[x], g[curr][i] + ShortestPath(i, x & (~(1 << i)), dp, g));
    }
    return dp[x];
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
        ll n; // Represents the number of nodes
        cin >> n;
        // matrix to store the adjancency matrix of the graph
        vector<vector<int>> g(n, vector<int>(n));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> g[i][j];

        // M has n set bits representing that no node has been visited uptill now
        ll M = (1 << n) - 1;
        vector<int> dp(M + 5, -1);

        cout << "The minimum possible distance in testcase " << tt << " is -> " << ShortestPath(0, M, dp, g) << endl;
    }
}