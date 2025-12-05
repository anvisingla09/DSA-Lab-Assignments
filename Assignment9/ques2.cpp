#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;

class Graph{
int V;
list<int> *l;
public:
Graph(int V){
  this->V = V;
  l = new list<int> [V];
}

void addEdges(int u , int v){
  l[u].push_back(v);
  l[v].push_back(u);
}

void DFShelper(int u , vector<bool> &vis){
  cout<<u<<" ";
  vis[u] = true;
  for(int v : l[u]){
    if(!vis[v]){
      DFShelper(v , vis);
    }
  }
  cout<<endl;
}

void DFS(){
  int u = 0;
  vector<bool> vis(V,false);
  DFShelper(u,vis);
  return;
}
};
int main(){
  Graph g(7);
  g.addEdges(0,1);
  g.addEdges(1,2);
  g.addEdges(2,3);
  g.addEdges(2,4);
  g.addEdges(3,5);
  g.addEdges(4,6);
  g.addEdges(5,6);

  
  g.DFS();
  
}
