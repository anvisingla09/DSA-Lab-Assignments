#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;
class Graph{
int V;
list<int> *l;
public:
Graph(int V){
  this->V = V;
  l = new list<int> [V];
}

void addEdges(int u, int v){
  l[u].push_back(v);
  l[v].push_back(u);
}

void BFS(){
  queue<int> q;
  vector<bool> vis(V , false);

   q.push(0);
   vis[0] = true;

  while(q.size()>0){
    int u = q.front();
    q.pop();

    cout<<u<<" ";
    for(int v : l[u]){
      if(!vis[v]){
        vis[v] = true;
        q.push(v);
      }
    }
  }
  cout<<endl;
}



};
int main(){
  Graph g(6);
  g.addEdges(0,1);
  g.addEdges(1,3);
  g.addEdges(1,5);
  g.addEdges(5,2);
  g.addEdges(5,4);
  g.addEdges(2,4);

  g.BFS();
 
  
}
