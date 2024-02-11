// Pratham Gupta - 220001060
// Question-->
// ****************************************************************************************
//  Given two sorted arrays nums1 and nums2 of size m and n, respectively;
// return the median of the two sorted arrays.
// ****************************************************************************************
//-- Change the input file for the testcases
//---- The Output comes in the output file
//------ The first line in output.in represents the no. of test cases
// Each test case contains ->
// ---> integers n and m
// ------n x m integer matrix board where the cells are labeled from 1 to n2
// ------A row r and column c has a snake or ladder if v[r][c] != -1.
// ------The destination of that snake or ladder is v[r][c].
// ------Squares 1 and n*n do not have a snake or ladder.

// Code starts here
#include <bits/stdc++.h> //Including the header files
#include <cstdio>
using namespace std;
#define ll long long

vector<int> d;
pair<int, int> pos(int a, int n)
{
    int row = n - ceil(a * 1.0 / n);
    int col;
    if ((n - row) & 1)
    {
        col = a % n - 1;
        if (col < 0)
            col += n;
    }
    else
    {
        col = a % n;
        if (col)
            col = n - col;
    }
    return {row, col};
}
int mx;
int bfs(int n, int m, vector<vector<int>> &v)
{
    queue<int> q;
    q.push(n);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        int y = min(mx, x + 6);
        for (int j = x + 1; j <= y; j++)
        {
            pair<int, int> l = pos(j, m);
            int z = j;
            if (v[l.first][l.second] != -1)
            {
                z = v[l.first][l.second];
            }
            if (d[z] == -1)
            {
                d[z] = d[x] + 1;
                q.push(z);
            }
        }
    }
    return d[mx];
}

int snakesAndLadders(vector<vector<int>> &v)
{
    int n = v.size();
    mx = n * n;
    d.clear();
    d.resize(mx + 1, -1);
    d[1] = 0;
    int ans = bfs(1, n, v);
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
        vector<vector<int>> board(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> board[i][j];
            }
        }

        ll ans = snakesAndLadders(board);

        cout << "The minimum no. of moves in testcase " << tt << " is -> " << ans << endl;
    }
}