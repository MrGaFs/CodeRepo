# Code repository

## code template 

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
    //O(n)
    DSU(int n)
    {
        iota(par, par+n, 0);
        iota(set, set+n, 0);
        iota(pos, pos+n, 0);
        fill(sz, sz+n, 1);
        cnt = n;
    }
    // O(ackermann)
    int find(int n)
    {
        if(n == par[n])
        return n ;
        return par[n] = find(par[n]);
    }
    // O(ackermann)
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
    // O(n)
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
### BIT (binary indexed tree) => Fenwick Tree

the idea of **BIT** is that is to make a dynamic prefix sum
#### Normal BIT
> This is normal bit that only capable off update single element in log(n)
```c++
const int N = 1 << 18 ;
struct BIT
{
        int tree[N] ;
    void init()
    {
        memset(tree , 0 , sizeof tree);
    }
    //O(log(n))
    void add(int pos, int val)
    {
        for(++pos ; pos <= N ; pos += (pos & (-pos)))
        tree[pos - 1] += val ;
    }
    //O(log(n))
    int get(int pos)
    {
        int tmp = 0;
        for(++pos ; pos ; pos -= (pos &(-pos)))
        tmp += tree[pos - 1];
        return tmp;
    }
    // this if tree is Sorted
    //O(log(n))
    int find(int t)
    {
        int st = 0;
        for(int sz = N >> 1;sz ; sz >>= 1)
        {
            if(tree[st + sz -1] < t)
                t -= tree[(st += sz) -1];
        }
        return st ;
    }
};
```

#### update ranges BIT

> this is ranges update BIT

```c++
struct bitRange
{
    int m[N], c[N];
    void add(int pos, int mVal, int cVal)
    {
        for(++pos; pos <= N;pos += (pos & (-pos)))
        {
            m[pos - 1] += mVal;
            c[pos - 1] += cVal;
        }
    }
    int get(int pos)
    {
        int ret = 0 , x = pos;
        for(++ pos ; pos ; pos -= (pos & (-pos)))
        {
            ret += m[pos - 1] * x + c[pos - 1];
        }
        return ret ;
    }
    void addRange(int st, int en, int val)
    {
        add(st, val, val - val * st);
        add(en + 1, - val , val * en);
    }
};
```

## Range Query DS

> Use according to this table

|complexity|Sparse table    |Sqrt Decomp|Segment tree|
|---------|-----------------|-----------|------------|
|Time    |                  |     | |
|Space    | O(n * log(n)) |     | |


### Sparse Table

it's one of way's to make a range Query

```c++
const int N = (1 << 17) , LG = 17;
int sp[N][LG], lg[N], arr[N], n;
void pre()
{
    lg[0] = -1;
    for(int i = 0 ; i < N - 1; ++i)
    {
        sp[0][i] = i;
        lg[i + 1] = lg[i] + !( i & (i + 1));
    }
}

void buildSP()
{
    static int __=(pre(), 0);
    for(int j = 1 ; (1 << j) <= n; ++j)
    {
        for(int i = 0 ; i + (1 << j) <= n ; ++i)
        {
            int a = sp[j - 1][i],
            b = sp[j - 1][i + (1 << (j - 1))];
            sp[j][i] = arr[a] < arr[b] ? a:b;
        }
    }
}
int getMnInd(int st, int en)
{
    int sz = en - st + 1;
    int l = lg[sz];
    int a = sp[l][st],
    b = sp[l][en - (1<<l) + 1];
    return arr[a] < arr[b] ? a : b;
}
```

### Sqrt Decomposition

Another way to make range query but support updating

```c++
const int N = 1e5 + 5, SQ = 317;
int arr[N], pre[SQ], n, sq;

int RMQ(int st, int en)
{
    int stB = st / sq, enB = en / sq;
    if(stB == enB)
        return *min(arr + st, arr + en + 1);
    int ret = min(*min_element(arr + st , arr + (stB + 1)* sq),
    *min_element(arr + enB * sq, arr + en + 1));
    if(stB + 1 != enB)
        ret = min(ret , *min_element(pre + stB + 1, pre + enB));
    return ret;
}
void update(int pos, int val)
{
    arr[pos] = val;
    pre[pos / sq] = min(pre[pos / sq], val);
}
```

