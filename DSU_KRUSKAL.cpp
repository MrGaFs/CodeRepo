
/******* Edge Struct ************/
struct edge {
int from , to , w ;

  edge(int from , int to , int w):from(from),to (to),w(w){}

 //comparing 

  bool operator < (const edge & e)const {
    return w > e.w;
  }

};
 
/******* Disjoin Set Struct ************/

struct DSU{

   //variables

  vector < int > rank ,parent;
  int forest;

   // constructor

  DSU(int n){
    rank = parent = vector <int> (n+1), forest = n;
    for ( int i = 0 ; i <= n ; ++i )
      rank [i] = 1 , parent [i] = i ;
  }
  
  //find parent function 

  int find_par(int node){
  
    if ( parent [node] == node )return node ;
    return parent [node] = find_par(parent[node]); 
  
  }

  //linking two edges function 

  void link (int x, int y){

   if( rank[x] > rank [y] )swap (x,y);
    parent [x] = y;
    if (rank [x] == rank [y] )y++;
  
  }

  //union checker function 

  bool union_dsu(edge e){

    int x = find_par(e.from), y = find_par(e.to) ;

   if(x != y) {
     link (x,y);
     forest --;
   }

  return x!=y;
 
  }

};

/******** kruskal MST Function ********/

pair < int , vector<edge>>mst(vector <edge> edgeList,int n){
  // DSU Struct Declaration 
  DSU graph(n);
  vector <edge>edges;
  int cost = 0 ;
  
  //priority_queueu to get the minimum
  
  priority_queue <edge> q;
  for (auto it :edgeList) q.push(it);

  // making the tree 

  while (!q.empty()){
 edge e = q.top () ; q.pop();
  if (graph.union_dsu(e)){
    cost+=e.w;
    edges.push_back(e);
   }
  }
   
   //reuturn false or the tree 

  if (edges.size() != n ) return {-OO,vector <edge> ()};
  return {cost,edges};

};
