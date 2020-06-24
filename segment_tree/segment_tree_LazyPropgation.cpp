#include<bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#define pb push_back
#define Ceil(a,b)              ((a)+(b)-1)/(b)
#define MrGAFs                 file();
#define rep(i,limits)          for(int i = 0;i<(limits);++i)
#define allr(v)                ((v).rbegin()), ((v).rend())
#define all(v)                 ((v).begin()), ((v).end())
#define endl                   "\n"
#define sz(v)	               ((int)((v).size()))
#define rt(v)                  return cout<<v,0;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const int oo = INT_MAX;
const ll OO = LLONG_MAX;
using namespace std;
int dx[] = { 0, 1, 0, -1, 1, 1, -1, -1 };
int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
int dx1[] = { -1, 1, 0, 0 };
int dy1[] = { 0, 0, -1, 1 };

	//classes
   class segment_tree{
private :
 //for all methods we call (p=1,s=0,e=n-1)
     int n;
     vector <int> a , seg ,lazy; 
    
       void check(int p,int s,int e) {
        if(lazy[p]!=0) {
            seg[p] += lazy[p];
            if(s!=e) {
                lazy[2*p] += lazy[p];
                lazy[2*p+1] += lazy[p];
            }
            lazy[p] = 0;
        }
    }
    void build(int p,int s,int e) {
        check(p,s,e);
        
        if(s==e) {
            seg[p] = a[s];
            return;
        }
        
        build(2*p,s,(s+e)/2);
        build(2*p+1,(s+e)/2+1,e);
        
        seg[p] = min(seg[2*p], seg[2*p+1]);
    }





public:
 //for all methods we call (p=1,s=0,e=n-1)
      segment_tree(int n,vector <int> v){
      seg =lazy=vector <int > (4*n);
      a=v;
      build(1,0,n-1);
     }

    



    void update_val(int p,int s,int e,int i,int v) {
        check(p,s,e);
        
        if(s==e) {
            seg[p] = v;
            return;
        }
        
        if(i<=(s+e)/2) update_val(2*p,s,(s+e)/2,i,v);
        else update_val(2*p+1,(s+e)/2+1,e,i,v);
        
        seg[p] = min(seg[2*p],seg[2*p+1]);
    }
    
 

    void update_range(int p,int s,int e,int a,int b,int v) {
        check(p,s,e);
        
        if(s>=a && e<=b) {
            seg[p] += v;
            
            if(s!=e) {
                lazy[2*p] += v;
                lazy[2*p+1] += v;
            }
            
            return;
        }
        
        if(s>b || e<a)
            return;
        
        update_range(2*p,s,(s+e)/2,a,b,v);
        update_range(2*p+1,(s+e)/2+1,e,a,b,v);
        
        seg[p] = min(seg[2*p],seg[2*p+1]);
    }
    




    int get(int p,int s,int e,int a,int b) {
        check(p,s,e);
        
        if(s>=a && e<=b)
            return seg[p];
        
        if(s>b || e<a)
            return oo; 
        
        return min(get(2*p,s,(s+e)/2,a,b), get(2*p+1,(s+e)/2+1,e,a,b));
    }
   };



      void file (){
      #ifndef ONLINE_JUDGE 
        bool x = freopen ("in.txt", "r", stdin);
        x = freopen ("out.txt", "w", stdout);
      #else
#endif
  ios_base::sync_with_stdio (false);
  cout.tie (NULL);
  cin.tie (NULL);
}

  /******Functions*********/
  

  
  /******Main Function*********/
int main (){
  MrGAFs 
}       