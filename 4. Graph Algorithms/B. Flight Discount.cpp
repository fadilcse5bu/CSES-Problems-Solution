#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll dis[100005][2];
int ck[100005];
vector <pair<int, int>> G[100005];

void dijsktra(int s, int n) {
  for(int i = 0; i <= n; i++) {
    dis[i][0] = 1e18;
    dis[i][1] = 1e18;
    ck[i] = 0;
  }
  dis[1][0] = 0;
  dis[1][1] = 0;
  priority_queue <pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
  pq.push({0, s});
  while(!pq.empty()) {
    ll x = pq.top().second;
    pq.pop();
    if(ck[x] == 2) continue;
    ck[x]++;

    for(int i = 0; i < G[x].size(); i++) {
      ll val = min(dis[x][0] + (G[x][i].second / 2), dis[x][1] + G[x][i].second);
      if(val < dis[G[x][i].first][1]) {
        dis[G[x][i].first][1] = val;
        pq.push({dis[G[x][i].first][1], G[x][i].first});
      }
      val = dis[x][0] + G[x][i].second;
      if(val < dis[G[x][i].first][0]) {
        dis[G[x][i].first][0] = val;
        pq.push({dis[G[x][i].first][0], G[x][i].first});
      }
    }
  }
}

int main()
{
  int n, m;
  cin >> n >> m;
  while(m--) {
    ll a, b, c;
    cin >> a >> b >> c;
    G[a].push_back({b, c});
  }

  dijsktra(1, n);

  cout << dis[n][1] << endl;

  return 0;
}
