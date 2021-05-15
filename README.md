# Code repository

# code template 

```c++
#include<bits/stdc++.h>
using namespace std;

/* ______ Defines _____ */

#define Ceil(a, b) ((a) + (b)) / (b)
#define MrGAFs fast_IO()
#define all(v) ((v).begin()), ((v).end())
#define endl '\n'
#define eps 1e-9

/* ______ PreDefined vars _____ */

const int oo = INT_MAX;
const long long OO = LLONG_MAX;
const int N = 1e5 + 10;
int dx[] = {1, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
int dx1[] = {0, -1, 0, 1};
int dy1[] = {-1, 0, 1, 0};

/* ______ Fast I/o put _____ */

void fast_IO()
{
ios_base::sync_with_stdio(false);
cout.tie(NULL);
cin.tie(NULL);
}
/* ______ functions ______ */
/* ______ main function ______ */
int main()
{
	
}
```

## Data Structures

### DSU

The idea of dsu is a fast way to combine sets together

```c++
struct DSU
{
    int par[N], sz[N], set[N], pos[N], tail[N] ,nxt[N], cnt;
    DSU(int n)
    {
        iota(par, par+n, 0);
        iota(set, set+n, 0);
        iota(pos, pos+n, 0);
        fill(sz, sz+n, 1);
        cnt = n;
    }
    int find(int n)
    {
        if(n == par[n])
        return n ;
        return par[n] = find(par[n]);
    }
    bool merge(int u, int v)
    {
    	u = find(u);
    	v = find(v);
    	if(u == v)
    		return false;
    	if(u < v)
            swap(u, v);
    	par[v] = u ;
    	sz[u] += sz[v];
    	int p = pos[v];
    	pos[set[p] = set[--cnt]] = p ;
        int &t = tail[u];
        nxt[t] = v;
        t = tail[v];
    	return true;
    }
    string toString()
    {
        stringstream ss;
        ss << '[';
        for (int i = 0; i < cnt; ++i)
        {
        ss << '{';
        for (int u = sets[i]; ~u; u = nxt[u])
        ss << u << ",}"[!~nxt[u]];
        ss << ",]"[i + 1 == cnt];
        }
        return ss.str();
    }
};
```

