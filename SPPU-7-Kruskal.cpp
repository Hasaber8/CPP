#include<iostream>
#include <vector>
using namespace std;
#define I INT_MAX  // Infinity
void Union(int u,int v,int s[])
{
    if(s[u]<s[v])
    {
        s[u]+=s[v];
        s[v]=u;
    }
    else
    {
        s[v]+=s[u];
        s[u]=v;
    }
}

int Find(int u,int s[])
{
    int x=u,v{};
    while (s[x]>0)
    {
        x=s[x];
    }
    while (u !=x)
    {
        v = s[u];
        s[u] = x;
        u = v;
    }
    return x;
}
void kruskalsMST( vector<vector<int>>& edges,int V,int E)
{
    int T[3][V-1];  // Solution array
    int track[E] {0};  // Track edges that are included in solution
    int set[V+1] = {-1, -1, -1, -1, -1, -1, -1, -1};  // Array for finding cycle
    int i{};
    while (i<V-1)
    {
        int min =I,u{},v{},k{};
        for (size_t j = 0; j < V; j++)
        {
            if(track[j]==0 && min>edges[2][j])
            {
                min=edges[2][j];
                u=edges[0][j];
                v=edges[1][j];
                k=j;
            }
        }
        if (Find(u, set) != Find(v, set)){
            T[0][i] = u;
            T[1][i] = v;
            T[2][i] = min;
            // Perform union
            Union(Find(u, set), Find(v, set), set);
            i++;
        }
        track[k] = 1;
    }
    cout << "\nMinimum Cost Spanning Tree Edges\n" << "\n";
    int sum{};
    for (size_t i = 0; i < V-1; i++)
    {
        cout<<"( "<<T[0][i]<<"--->"<<T[1][i]<<" ) Cost---> "<<T[2][i]<<"\n";
        sum+=T[2][i];
    }
    cout<<"Total cost of the given MST is "<<sum<<"\n";
    
}
int main()
{
    int V{},E{};
    cout<<"Enter number of vertices\n";
    cin>>V;
    cout<<"Enter number of edges\n";
    cin>>E;
    vector<vector<int>> edges(3,vector<int>(E,I));
    for (size_t i = 0; i < E; i++)
    {
        cout<<"Enter Source , Destination , Weight\n";
        cin>>edges[0][i]>>edges[1][i]>>edges[2][i];
    }
    kruskalsMST(edges,V,E);
}
