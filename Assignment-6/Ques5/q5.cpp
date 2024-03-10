// Pratham Gupta - 220001060
// Question-->
// ****************************************************************************************
//  Find if a directed graph contain articulation nodes and bridges.
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

void dfs(int x, int parent, int time, vector<vector<int>> &v, vector<int> &disc, vector<int> &low, vector<bool> &isVis, vector<int> &ap, vector<pair<int, int>> &bridges)
{
    isVis[x] = 1;

    int children = 0;
    disc[x] = low[x] = time++;
    for (auto it : v[x])
    {
        if (!isVis[it])
        {
            children++;
            dfs(it, x, time, v, disc, low, isVis, ap, bridges);

            low[x] = min(low[x], low[it]);
            if (parent != -1 && disc[x] <= low[it])
            {
                ap[x] = 1;
            }
            if (disc[x] < low[it])
            {
                bridges.push_back({x, it});
            }
        }
        else if (it != parent)
        {
            low[x] = min(low[x], low[it]);
        }
    }
    if (parent == -1 && children >= 2)
    {
        ap[x] = 1;
    }
}

vector<int> articulationPoints(int n, vector<vector<int>> &v, vector<pair<int, int>> &bridges)
{
    vector<bool> isVis(n, false);
    vector<int> disc(n);
    vector<int> low(n);
    vector<int> ap(n, 0);
    int time = 1;
    for (int i = 0; i < n; i++)
    {
        if (!isVis[i])
        {
            dfs(i, -1, time, v, disc, low, isVis, ap, bridges);
        }
    }
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (ap[i])
        {
            ans.push_back(i);
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
            graph[b].push_back(a);
        }
        vector<pair<int, int>> bridges;
        vector<int> articulation_points = articulationPoints(n, graph, bridges);
        cout << "the Number of articulation points in testcase " << tt << " is -> " << articulation_points.size() << endl;
        for (auto it : articulation_points)
        {
            cout << it << " ";
        }
        cout << endl;
        cout << "the Number of bridges in testcase " << tt << " is -> " << bridges.size() << endl;
        for (auto it : bridges)
        {
            cout << it.first << " " << it.second << endl;
        }
        cout << endl;
    }
}