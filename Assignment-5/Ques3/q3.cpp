// Pratham Gupta - 220001060
// Question-->
// ****************************************************************************************
// A Clique is a subgraph of a graph such that all vertices in the subgraph are completely connected.
// Given a Graph, find if it can be divided into two Cliques
// ****************************************************************************************
//-- Change the input file for the testcases
//---- The Output comes in the output file
//------ The first line in output.in represents the no. of test cases
//--------- The next 2t lines follow
//     1---> The no. of elements in vector v (n) ant the value of k => (k th largest element)
//     2---> (n) Elements separated by " "(space) representing the elements in v

// Code starts here
#include <bits/stdc++.h> //Including the header files
#include <cstdio>
using namespace std;
#define ll long long

bool isBipartite(int n, vector<vector<int>> &v, vector<int> &color, int s)
{
    color[s] = 1;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (i != temp)
            {
                if (!v[temp][i] && color[i] == -1)
                {
                    q.push(i);
                    if (color[temp] == 0)
                    {
                        color[i] = 1;
                    }
                    else
                    {
                        color[i] = 0;
                    }
                }
                else if (!v[temp][i] && color[i] == color[temp])
                {
                    return false;
                }
            }
        }
    }
    return true;
}

bool containsTwoCliques(int n, vector<vector<int>> &v)
{
    vector<int> color(n, -1);

    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (!isBipartite(n, v, color, i))
                return false;
        }
    }
    return true;
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
        ll n;
        cin >> n;

        vector<vector<int>> v(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> v[i][j];

        bool ans = containsTwoCliques(n, v);

        cout << "The retult for tescase " << tt << " is -> " << (ans ? "YES" : "NO") << endl;
    }
}