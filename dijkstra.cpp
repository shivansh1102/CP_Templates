/*Template for dijkstra algorithm*/ 
const lli INF = 1e18;
vector<pair<int,lli>>adj[MAXN+1];
lli dist[MAXN+1];
int par[MAXN+1];
void dijkstra(int n, int src)
{
    for(int i = 1; i <= n; i++)
    dist[i] = INF;
    priority_queue<pair<lli,int>, vector<pair<lli,int>>, greater<pair<lli,int>>>pqu;
    dist[src] = 0;
    pqu.push({0, src});
    int curr, wt;
    while(!pqu.empty())
    {
        curr = pqu.top().second;
        wt = pqu.top().first;
        pqu.pop();
        if(wt > dist[curr])
        continue;
        for(auto neigh : adj[curr])
        {
            int v = neigh.first, w = neigh.second;
            if(dist[v] > dist[curr] + w)
            {
                par[v] = curr;
                dist[v] = dist[curr] + w;
                pqu.push({dist[v], v});
            }
        }
    }  
}
