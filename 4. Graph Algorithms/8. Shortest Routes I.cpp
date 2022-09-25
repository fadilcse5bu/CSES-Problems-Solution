#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector <pair<ll, ll>> g[100001];
ll len[100001];
bool processed[100001];

void dijkstra(ll source) {
  priority_queue <pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
  pq.push({0, source});

  while(!pq.empty()) {
    ll u = pq.top().second;
    pq.pop();
    if(processed[u]) continue;
    processed[u] = true;
    for(int i = 0; i < g[u].size(); i++) {
      ll v = g[u][i].first, cost = g[u][i].second;
      if(len[u] + cost < len[v]) {
        len[v] = len[u] + cost;
        pq.push({len[v], v});
      }
    }
  }
}

int main()
{
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    g[a].push_back({b, c});
  }

  for(int i = 0; i <= n; i++) len[i] = 1e18;
  len[1] = 0;

  dijkstra(1);

  for(int i = 1; i <= n; i++) cout << len[i] << ' ';

  return 0;
}
