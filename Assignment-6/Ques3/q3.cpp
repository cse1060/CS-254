// Pratham Gupta - 220001060
// Question-->
// ****************************************************************************************
// Find strongly connected components from a directed graph.
// ****************************************************************************************
//-- Change the input file for the testcases
//---- The Output comes in the output file
//------ The first line in output.in represents the no. of test cases
//     1---> The number of nodes n and the number of edges m
//     2---> Then m lines follow
//     3---> each line contains  a  and b signifying a edge from a to b

// Code starts here
#include <bits/stdc++.h> //Including the header files
#include <cstdio>
using namespace std;
#define ll long long

void dfs(int x, vector<vector<int>> &v, vector<bool> &isVis, stack<int> &s)
{
    isVis[x] = true;
    for (auto it : v[x])
    {
        if (!isVis[it])
        {
            dfs(it, v, isVis, s);
        }
    }
    s.push(x);
}

void scc(int x, vector<vector<int>> &g, vector<bool> &isVis)
{
    isVis[x] = true;
    for (auto it : g[x])
    {
        if (!isVis[it])
        {
            scc(it, g, isVis);
        }
    }
}

int kosaraju(int n, vector<vector<int>> &v)
{
    vector<bool> isVis(n, false);
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (!isVis[i])
        {
            dfs(i, v, isVis, s);
        }
    }
    vector<int> arr;
    while (!s.empty())
    {
        arr.push_back(s.top());
        s.pop();
    }

    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++)
    {
        for (auto it : v[i])
        {
            g[it].push_back(i);
        }
    }

    fill(isVis.begin(), isVis.end(), false);

    int ans = 0;
    for (auto it : arr)
    {
        if (!isVis[it])
        {
            ans++;
            scc(it, g, isVis);
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

        ll n, m;
        cin >> n >> m;
        vector<vector<int>> graph(n);
        for (int i = 0; i < m; i++)
        {
            ll a, b;
            cin >> a >> b;
            graph[a].push_back(b);
        }

        int strongly_connected_components = kosaraju(n, graph);

        cout << "the Number of strongly connected components in testcase " << tt << " is -> " << strongly_connected_components << endl;
    }
}