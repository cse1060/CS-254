// Pratham Gupta - 220001060
// Question-->
// ****************************************************************************************
// Consider a matrix, where each cell contains either a ’0’ or a ’1’; any cell containing a ’1’
// is called a filled cell. Two cells are said to be connected if they are adjacent to each other
// horizontally, vertically, or diagonally. If one or more filled cells are connected, they form a
// region. find the size of the largest region
// ****************************************************************************************
//-- Change the input file for the testcases
//---- The Output comes in the output file
//------ The first line in output.in represents the no. of test cases
//     1---> The grd values n and m
//     2---> (n*m) Elements separated by " "(space) and "\n"

// Code starts here
#include <bits/stdc++.h> //Including the header files
#include <cstdio>
using namespace std;
#define ll long long

int ans = 0;
vector<vector<int>> isVis;
int n, m;
vector<pair<int, int>> moves = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int dfs(int i, int j, vector<vector<int>> &v)
{

    if (i < 0 || j < 0 || i >= n || j >= m)
        return 0;
    if (isVis[i][j] == 1)
        return 0;
    isVis[i][j] = 1;
    if (v[i][j] == 0)
        return 0;

    int area = 0;

    for (int k = 0; k < 8; k++)
    {
        area += dfs(i + moves[k].first, j + moves[k].second, v);
    }

    return area + 1;
}

int maxArea(vector<vector<int>> &v)
{
    ans = 0;
    n = v.size();
    m = v[0].size();
    isVis.clear();
    isVis.resize(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 1 && isVis[i][j] == 0)
            {
                ans = max(ans, dfs(i, j, v));
            }
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
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }

        ans = maxArea(grid);

        cout << "the max region in testcase " << tt << " is -> " << ans << endl;
    }
}