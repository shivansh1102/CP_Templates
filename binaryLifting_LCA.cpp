/* Binary Lifting & LCA */
int level[200001];
int dp[200001][20];
void binaryLifting(vector<int>adj[], int u, int par)
{
    if(u==1)
    {
        for(int i=0; i<20; i++)
        dp[u][i]=-1;
    }
    else
    {
        dp[u][0]=par;
        for(int i=1; i<20; i++)
        {
            int parup = dp[u][i-1];
            if(parup<0)
            dp[u][i] = -1;
            else
            dp[u][i] = dp[parup][i-1];
        }
    }
    for(int v : adj[u])
    {
        if(v != par)
        binaryLifting(adj,v,u);
    }
}
int query(int u, int k)
{
    int ind = 0;
    while(k>0)
    {
        if(k&1)
        {
            u = dp[u][ind];
            if(u == (-1))
            return u;
        }
        k>>=1;
        ind++;
    }
    return u;
}
void findLevel(vector<int>adj[], int u, int par)
{
    level[u] = level[par] + 1;
    for(int v : adj[u])
    {
        if(v != par)
        {
            findLevel(adj,v,u);
        }
    }
}
void swap(int &u, int &v)
{
    int temp = u;
    u = v;
    v = temp;
}
int findLCA(int u, int v)
{
    if(level[u]<level[v])
    swap(u,v);
    int diff = level[u] - level[v];
    u = query(u,diff);
    if(u == v)
    return u;
    int u1,v1;
    for(int i=19; i>=0; i--)
    {
        u1 = dp[u][i];
        v1 = dp[v][i];
        if(u1!=v1)
        {
            u=u1,v=v1;
        }
    }
    return dp[u][0];
}
