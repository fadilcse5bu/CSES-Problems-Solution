#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector <tuple<int, int, int>> G;
ll dis[5005], par[5005];

int main()
{
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    G.push_back({a, b, c});
  }

  for(int i = 1; i <= n; i++) dis[i] = 1e18;

  int x = -1;
  for(int i = 0; i <= n; i++) {
    x = -1;
    for(auto [u, v, cost] : G) {
      if(dis[u] + cost < dis[v]) {
        dis[v] = dis[u] + cost;
        par[v] = u;
        x = u;
      }
    }
  }

  if(x == -1) {
    cout << "NO" << endl;
    return 0;
  }

  for(int i = 1; i <= n; i++) {
    x = par[x];
  }

  vector <int> path;
  for(int y = x; ; y = par[y]) {
    path.push_back(y);
    if(y == x && path.size() > 1) break;
  }

  reverse(path.begin(), path.end());
  cout << "YES" << endl;
  for(int i = 0; i < path.size(); i++) cout << path[i] << ' ';
  cout << endl;

  return 0;
}
