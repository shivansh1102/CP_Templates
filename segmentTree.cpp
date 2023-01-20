/*Template for segment tree */
const int MAXN = 100000; 
lli segtree[4*MAXN];
void combine(int v)
{
    segtree[v] = segtree[2*v] + segtree[2*v+1];
}
void buildTree(lli a[], int v, int tl, int tr)
{   
    if(tl == tr)
    {
        segtree[v] = a[tl];
        return;
    }
    int tm = (tl + tr)/2;
    buildTree(a, 2*v, tl, tm);
    buildTree(a, 2*v+1, tm+1, tr);
    combine(v);
}
lli query(int v, int tl, int tr, int ql, int qr)
{
    if(ql > qr)
    return 0;
    if(tl == ql && tr == qr)
    return segtree[v];
    int tm = (tl + tr)/2;
    return query(2*v, tl, tm, ql, min(tm,qr)) + query(2*v+1, tm+1, tr, max(ql,tm+1), qr);
}
void update(int v, int tl, int tr, int pos, int nval)
{
    if(tl == tr)
    {
        segtree[v] = nval;
        return;
    }
    int tm = (tl + tr)/2;
    if(pos <= tm)
    update(2*v, tl, tm, pos, nval);
    else
    update(2*v+1, tm+1, tr, pos, nval);
    combine(v);
}
