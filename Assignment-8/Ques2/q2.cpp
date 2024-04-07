// Pratham Gupta - 220001060
// Question-->
// ****************************************************************************************
// Given a graph with n nodes and m edges where each edge has a color (either black or
// green) and a cost associated with it. Find the minimum spanning tree of the graph such
// that every path in the tree is made up of alternating colored edges.
// ****************************************************************************************
//-- Change the input file for the testcases
//---- The Output comes in the output file
//------ The first line in output.in represents the no. of test cases
//     1---> The number of nodes n  and edges m
//     2---> the nodes x , y pf the edge , the weight and the color of edge
//      'B'->Black , 'G'->Green

// Code starts here
#include <bits/stdc++.h> //Including the header files
#include <cstdio>
using namespace std;
#define ll long long

int graph[18][18][2];
long long dp[1 << 18][18][2];

long long minWeight(int n, int m, int bit_mask, int prev, int col)
{
    if (bit_mask == ((1 << n) - 1))
    {
        return 0;
    }
    if (dp[bit_mask][prev][col == 1] != 0)
    {
        return dp[bit_mask][prev][col == 1];
    }

    ll ans = 1e9;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (graph[prev][i][j] && !(bit_mask & (1 << i)) && (j != col))
            {
                long long z = graph[prev][i][j] + minWeight(n, m, bit_mask | (1 << i), i, j);
                ans = min(z, ans);
            }
        }
    }

    return dp[bit_mask][prev][col == 1] = ans;
}

void makeGraph(vector<pair<pair<int, int>, pair<int, char>>> &vp, int m)
{
    for (int i = 0; i < m; i++)
    {
        int a = vp[i].first.first - 1;
        int b = vp[i].first.second - 1;
        int cost = vp[i].second.first;
        char color = vp[i].second.second;
        graph[a][b][color == 'G'] = cost;
        graph[b][a][color == 'G'] = cost;
    }
}

int getCost(int n, int m)
{
    long long ans = 1e9;
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, minWeight(n, m, 1 << i, i, 2));
    }
    return ans != 1e9 ? ans : -1;
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

        int n, m;
        cin >> n >> m;

        vector<pair<pair<int, int>, pair<int, char>>> v;
        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            char d;
            cin >> a >> b >> c >> d;
            v.push_back({{a, b}, {c, d}});
        }

        makeGraph(v, m);
        ll ans = getCost(n, m);

        cout << "the value of the MST with alternating edges weight in testcase " << tt << " is -> " << ans << endl;
        cout << endl;
    }
}