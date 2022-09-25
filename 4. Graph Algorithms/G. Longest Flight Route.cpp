#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int dis[100005], par[100005];
vector <int> ve[100005];

void dijkstra(int x) {
  priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({1, x});
  while(!pq.empty()) {
    int node = pq.top().second;
    pq.pop();
    for(int i = 0; i < ve[node].size(); i++) {
      if(dis[node] + 1 > dis[ve[node][i]]) {
        dis[ve[node][i]] = dis[node] + 1;
        par[ve[node][i]] = node;
        pq.push({dis[ve[node][i]], ve[node][i]});
      }
    }
  }
}

int main()
{
  int n, m;
  cin >> n >> m;
  while(m--) {
    int a, b;
    cin >> a >> b;
    ve[a].push_back(b);
  }

  for(int i = 1; i <= n; i++) {
    dis[i] = 1;
  }
  dis[n] = -1;

  dijkstra(1);

  if(dis[n] == -1) cout << "IMPOSSIBLE" << endl;
  else {
    vector <int> path;
    int p = n;
    path.push_back(n);
    while(p != 1) {
      path.push_back(par[p]);
      p = par[p];
    }

    cout << path.size() << endl;
    for(int i = path.size() - 1; i >= 0; i--) cout << path[i] << ' ';
    cout << endl;
  }


  return 0;
}
