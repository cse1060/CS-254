// Pratham Gupta - 220001060
// Question-->
// ****************************************************************************************
// Given a directed acyclic graph G with N vertices and M edges. The task is
// to find the length of the longest path in Graph.
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

vector<int> TopologicalSort(int n, vector<vector<int>> &graph, vector<int> &indegree)
{
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> ans;
    while (!q.empty())
    {
        int a = q.front();
        q.pop();
        ans.push_back(a);
        for (auto it : graph[a])
        {
            if (indegree[it])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
    }

    return ans;
}

int LongestPath(int n, vector<vector<int>> &graph, vector<int> ts_arr)
{
    vector<int> dist(n, 0);
    int ans = 0;

    for (auto it : ts_arr)
    {
        for (auto adj_node : graph[it])
        {
            dist[adj_node] = max(dist[it] + 1, dist[adj_node]);
            ans = max(ans, dist[adj_node]);
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
        vector<int> indegree(n, 0);
        for (int i = 0; i < m; i++)
        {
            ll a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            indegree[b]++;
        }

        vector<int> Toposort_arr = TopologicalSort(n, graph, indegree);
        int longest_path = LongestPath(n, graph, Toposort_arr);
        cout << "the longest path in testcase " << tt << " is -> "
             << longest_path << endl
             << endl;
    }
}