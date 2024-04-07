// Pratham Gupta - 220001060
// Question-->
// ****************************************************************************************
// Given an undirected weighted graph, a maximum spanning tree is a spanning tree having
// maximum weight. Devise algorithm to generate maximum spanning tree using union-find.
// ****************************************************************************************
//-- Change the input file for the testcases
//---- The Output comes in the output file
//------ The first line in output.in represents the no. of test cases
//     1---> The number of edges n
//     2---> The weight w of the edge and nodes x , y

// Code starts here
#include <bits/stdc++.h> //Including the header files
#include <cstdio>
using namespace std;
#define ll long long

class dsu // making a class dsu which helps  in the checkong of the cycles
{
public:
    int size;
    vector<int> parent; // Array to maintain the parent of each node (initially -1)
    // Negative parent means that the parent of this node is the node itself
    // if the parent value is -3 -> it means that the given node has 2 children and one itself

    dsu(int n) // Constructor to initialise the vector parent
    {
        for (int i = 0; i < n; i++)
        {
            parent.push_back(-1);
        }
    }

    int Find(int x) // Function to find the parent of any node (recurssive)
    {
        if (parent[x] < 0)
        {
            return x;
        }
        return Find(parent[x]);
    }

    bool Union(int x, int y) // Function to do the union of the nodes -> returns false if it results in cycle
    {
        int xPar = Find(x); // Parent of x
        int yPar = Find(y); // Parent of y

        if (xPar == yPar) // If parent of x and parent of y are same then it results in cycle
            return false;

        // Adding the parent with less children to the other parent
        if (parent[xPar] < parent[yPar])
        {
            parent[xPar] += parent[yPar];
            parent[yPar] = xPar;
        }
        else
        {
            parent[yPar] += parent[xPar];
            parent[xPar] = yPar;
        }
        return true;
    }
};

// Implementation of the Kruskal's algo using dsu
int Kruskals(vector<vector<int>> &edges)
{
    int tot_weight = 0;               // Total cost or weight of the MST
    sort(edges.begin(), edges.end()); // Sorting all the edges according to the weight

    dsu check_cycle(edges.size()); // Initiating an object of class dsu
    for (auto edge : edges)
    {
        int weight = edge[0];
        int node1 = edge[1];
        int node2 = edge[2];

        if (check_cycle.Union(node1, node2)) // If the given edge does not result in cycle then printing that edge
        {
            cout << "Edge: " << node1 << "->" << node2 << " :: weight - " << weight << endl;
            tot_weight += weight;
        }
    }
    return tot_weight;
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

        int n;
        cin >> n;
        vector<vector<int>> edges(n, vector<int>(3));
        for (int i = 0; i < n; i++)
        {
            cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        }

        int ans = Kruskals(edges);

        cout << "the value of the MST edges weight in testcase " << tt << " is -> " << ans << endl;
        cout << endl;
    }
}