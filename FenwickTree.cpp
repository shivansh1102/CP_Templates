/* Fenwick tree */
template<typename T>
class FenwickTree // point update, range query
{
    vector<T>bit; int size;
    public : 
    FenwickTree(int n = 0)
    {
        bit.assign(n+1, 0);
        size = n;
    }
    T query(int idx) // return prefix sum upto idx
    {
        T sum = 0;
        for(; idx > 0; idx -= (idx & -idx))
        sum += bit[idx];
        return sum;
    }
    void update(int idx, T addend) // add the value of addend at index idx
    {
        for(; idx <= size; idx += (idx & -idx))
        bit[idx] += addend;
    }
    void print() // for debugging
    {
        for(int i = 1; i <= size; i++)
        cout << bit[i] << " ";
        cout << endl;
    }
};
