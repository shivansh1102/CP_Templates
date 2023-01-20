/* DSU TEMPLATE */
struct subset
{
    int parent,rank;
};
void makeSet(subset dsu[], int m) // Initialise
{
    for(int i=1; i<=m; i++)
    {
        dsu[i].parent=i;
        dsu[i].rank=0;
    }
}
int Find(subset dsu[], int i) // PATH COMPRESSION
{
    if(i==dsu[i].parent)
    return i;
    dsu[i].parent=Find(dsu,dsu[i].parent);
    return dsu[i].parent;
}
void Union(subset dsu[], int i, int j) // UNION BY RANK
{
    if(dsu[i].rank>dsu[j].rank)
    dsu[j].parent=i;
    else if(dsu[i].rank<dsu[j].rank)
    dsu[i].parent=j;
    else
    {
        dsu[i].parent=j;
        dsu[j].rank++;
    }
}
/* Template 2*/
class DSU
{ 
    vector<int>parent, rank;
    public :
    DSU(int n)
    {
        parent.resize(n+1);
        rank.resize(n+1);
        for(int i = 1; i <= n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int Find(int u)
    {
        if(parent[u] == u)
            return u;
        parent[u] = Find(parent[u]);
        return parent[u];
    }
    void Union(int u, int v)
    {
        if(rank[u] > rank[v])
            parent[v] = u;
        else if(rank[u] < rank[v])
            parent[u] = v;
        else
        {
            parent[u] = v;
            rank[v]++;
        }
    }
    ~DSU()
    {
        parent.clear();
        rank.clear();
    }
};
