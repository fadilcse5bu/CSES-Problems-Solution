#include<bits/stdc++.h>
using namespace std;
#define ll long long int

struct Edge {
  int u, v, w;
};
vector <Edge> E;
ll dist[2505], n;
bool col[2505], ck;
vector <int> G[2505], cost[2505];

void Set(int n) {
  for(int i = 0; i <= n; i++) {
    col[i] = 0;
  }
  ck = 0;
}

void dfs(int x, int v) {
  col[x] = 1;
  if(x == v) ck = 1;
  for(int i = 0; i < G[x].size(); i++) {
    if(col[G[x][i]] == 0) dfs(G[x][i], v);
  }
}

void bellman_ford(int s) {
  for(int i = 1; i <= n; i++) {
    dist[i] = -1e18;
  }
  dist[s] = 0;

  for(int i = 1; i <= n; i++) {
    for(auto i = 0; i < E.size(); i++) {
      if(dist[E[i].v] < dist[E[i].u] + E[i].w) {
        dist[E[i].v] = dist[E[i].u] + E[i].w;
      }
    }
  }

  for(auto i = 0; i < E.size(); i++) {
    if(dist[E[i].v] < dist[E[i].u] + E[i].w) {
      dist[E[i].v] = dist[E[i].u] + E[i].w;

      Set(n);
      dfs(1, E[i].v);
      bool c = ck;
      Set(n);
      dfs(E[i].v, n);
      if(c == 1 and ck == 1) {
        dist[n] = -1;
        return;
      }
    }
  }
}

int main()
{
  int m;
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    G[u].push_back(v);
    cost[u].push_back(w);
    struct Edge Ed;
    Ed.u = u;
    Ed.v = v;
    Ed.w = w;
    E.push_back(Ed);
  }

  bellman_ford(1);

  cout << dist[n] << endl;

  return 0;
}
