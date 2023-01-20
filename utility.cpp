/* 'a' raise to 'n' modulo 'md' */
lli powermod(lli a, lli n, lli md)
{
	a = a%md;
    lli res=1;
    while(n)
    {
        if(n&1)
        res= (res*a)%md;
        n>>=1;
        a = (a*a)%md;
    }
    return res;
}
--------------------------------------------------------------------------------------------------------------------------------------------------------------
/* Sieve */
const int MAXA = 1e7;
int spf[MAXA+1];
bool isPrime[MAXA+1];
void sieve()
{
    for(int i = 2; i <= MAXA; i++)
    {
        spf[i] = i;
        isPrime[i] = true;
    }
    for(lli i = 2; i*i <= MAXA; i++)
    {
        if(isPrime[i])
        {
            for(lli j = i*i; j <= MAXA; j += i)
            {
                isPrime[j] = true;
                if(spf[j] == j)
                spf[j] = i;
            }
        }
    }
}
--------------------------------------------------------------------------------------------------------------------------------------------------------------
/* string to int */ --- C++ STL => stoi() & stoll()
int stringToInt(string &s)
{
    int n=0;
    for(int i=0; i<s.size(); i++)
    {
        n = n*10 + (s[i]-'0');
    }
    return n;
}
--------------------------------------------------------------------------------------------------------------------------------------------------------------
/* lli to string */ C++ STL => to_string()
string intTostr(lli x)
{
    if(x == 0)
    return "0";
    string s;
    while(x!=0)
    {
        s+=('0'+(x%10));
        x/=10;
    }
    reverse(s.begin(),s.end());
    return s;
}
----------------------------------------------------------------------------------------------------------------------------------------------
/* Modular multiplicative inverse */
// ax + by = gcd(a,b)
// bx1 + (a%b)y1 = gcd(b,a%b)
// x = y1 and y = x1 - (a/b)*y1
lli gcdExtended(lli a, lli b, lli &x, lli &y)
{
    if(b==0)
    {
        x = 1;
        y = 0;
        return a;
    }
    lli x1,y1;
    lli gcd = gcdExtended(b,a%b,x1,y1);
    x = y1; y = x1 - (a/b)*y1;
    return gcd;
}
lli modInverse(lli a, lli mod)
{
    // assuming gcd(a,mod)=1
    lli x,y;
    // a.x is congruent to 1 modulo mod
    lli gcd = gcdExtended(a,mod,x,y);
    x = (x%mod + mod)%mod;
    return x;
}
--------------------------------------------------------------------------------------------------------------------------------------------------------------
/* Template for ordered_set */
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; 
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the kth largest element.(0-based)
// declare variable as:  ordered_set A;
--------------------------------------------------------------------------------------------------------------------------------------------------------------

