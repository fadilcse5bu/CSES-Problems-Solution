#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector <int> G[100005], path;
int col[100005], current_node[100005], parent[100005], node = -1;

void dfs(int x) {
  col[x] = 1;
  current_node[x] = 1;
  for(int i = 0; i < G[x].size(); i++) {
    parent[G[x][i]] = x;
    if(current_node[G[x][i]] == 1) {
      if(node == -1) {
        node = x;
        int p = parent[node];
        path.push_back(node);
        while(p != node) {
          path.push_back(p);
          p = parent[p];
        }
        path.push_back(node);
      }
    }
    if(col[G[x][i]] == 0) {
      dfs(G[x][i]);
    }
  }
  current_node[x] = 0;
}

int main()
{
  int n, m;
  cin >> n >> m;
  while(m--) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
  }

  for(int i = 1; i <= n; i++) {
    if(col[i] == 0) {
      dfs(i);
    }
  }

  reverse(path.begin(), path.end());
  if(path.size() != 0) {
    cout << path.size() << endl;
    for(int i = 0; i < path.size(); i++) cout << path[i] << ' ';
    cout << endl;
  }
  else cout << "IMPOSSIBLE" << endl;


  return 0;
}
