#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graph
{
private:
    int V, E;
    vector<pair<int, pair<int, int>>> edges;
    vector<pair<int, pair<int, int>>> MST;

public:
    Graph(int V, int E);
    void addEdge(int u, int v, int w);
    int kruskalMST();
    void printMST();
};
Graph::Graph(int V, int E)
{
    this->V = V;
    this->E = E;
}
void Graph::addEdge(int u, int v, int w)
{
    edges.push_back({w, {u, v}});
}

void Graph::printMST()
{
    vector<pair<int, pair<int, int>>>::iterator it;
    for (it = MST.begin(); it != MST.end(); it++)
    {
        cout << it->second.first << " - " << it->second.second << endl;
    }
}
struct DisjointSet
{
    int *parent, *rnk;
    int n;

    DisjointSet(int n)
    {
        this->n = n;
        parent = new int[n + 1];
        rnk = new int[n + 1];

        for (int i = 0; i <= n; i++)
        {
            rnk[i] = 0;
            parent[i] = i;
        }
    }
    int Find(int u)
    {
        if (u == parent[u])
            return parent[u];
        else
            return Find(parent[u]);
    }

    void Union(int x, int y)
    {
        x = Find(x);
        y = Find(y);
        if (x != y)
        {
            if (rnk[x] < rnk[y])
            {
                rnk[y] += rnk[x];
                parent[x] = y;
            }
            else
            {
                rnk[x] += rnk[y];
                parent[y] = x;
            }
        }
    }
};
int Graph::kruskalMST()
{
    int MSTWeight = 0; // sum of all vertex weights
    sort(edges.begin(), edges.end());
    // for all u in G_v
    //     MAKE-SET(u)
    DisjointSet ds(this->V);

    vector<pair<int, pair<int, int>>>::iterator it;
    // for all edges in G
    for (it = edges.begin(); it != edges.end(); it++)
    {
        int u = it->second.first;
        int v = it->second.second;

        int setU = ds.Find(u);
        int setV = ds.Find(v);

        if (setU != setV)
        {
            int w = it->first;
            MST.push_back({w, {u, v}});
            MSTWeight += it->first;

            ds.Union(setU, setV);
        }
    }
    return MSTWeight;
}
int main()
{
    int V, E;
    cout << "Number of vertices: " << endl;
    cin >> V;
    cout << "Number of edges: " << endl;
    cin >> E;
    Graph g(V, E);
    int u, v, w;
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    int weight = g.kruskalMST();
    cout << "MST: " << endl;
    g.printMST();
    cout << "Weight of MST is: " << weight;

    return 0;
}