#include<bits/stdc++.h>
#define Ceil(a,b)              ((a)+(b)-1)/(b)
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
int dx[] = { 0, 1, 0, -1, 1, 1, -1, -1 };
int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
int dx1[] = { -1, 1, 0, 0 };
int dy1[] = { 0, 0, -1, 1 };
using namespace std; 


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
vector<vector<int>> adj, SCC, CCG;
vector<int> low_link, dfns, comp;
vector<pair <int,int >> bridges;
vector<bool> inStack;
stack <int> st;
int dfn;
void tarjan(int node) {
	low_link[node] = dfns[node] = ++dfn;
	st.push(node);
	inStack[node] = true;
	for (auto child:adj[node]){
		if (dfns[child] == -1) {
			tarjan(child);
			low_link[node] = min(low_link[node], low_link[child]);
		}
	    if (inStack[child]) {
			low_link[node] = min(low_link[node], dfns[child]);
		}
	}
	if (low_link[node] == dfns[node]) {
		int x = -1;
		SCC.push_back(vector<int>());
		while (x!=node) {
			x = st.top(); st.pop();
			inStack[x] = false;
			SCC.back().push_back(x);
		}
	}

}
 
void bridges_c (int node ,int par){
    low_link[node] = dfns[node] = ++dfn;
	for (auto child:adj[node]){
		if (dfns[child] == -1) {
			bridges_c(child,node);
			low_link[node] = min(low_link[node], low_link[child]);
		}
		else if (child != par) {
			low_link[node] = min(low_link[node], dfns[child]);
		}
	}
	if (low_link[node] == dfns[node] && par != -1)bridges.push_back({par,node});
} 

bool root;
set<int>art;
void art_c(int node,int par) {
	dfns[node] = low_link[node] = ++dfn;
	for (auto child : adj[node])
		if (dfns[child] == -1) {
			art_c(child, node);
			low_link[node] = min(low_link[node], low_link[child]);
			if (low_link[child] >= dfns[node]) {
				if (dfns[node] == 1 && root==false)root = true;
				else art.insert(node);
			}
		}
		else if( par != child)
		low_link[node] = min(low_link[node],dfns[child]);
	 }

int main (){

}