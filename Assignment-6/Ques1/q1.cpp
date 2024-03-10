// Pratham Gupta - 220001060
// Question-->
// ****************************************************************************************
// Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find
// Topological Sorting of that Graph.
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

void TopologicalSort(int n, vector<vector<int>> &graph, vector<int> &indegree)
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
    for (auto it : ans)
    {
        cout << it << " ";
    }
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

        cout << "the Topological Sort in testcase " << tt << " is ->\n";
        TopologicalSort(n, graph, indegree);
        cout << endl;
    }
}