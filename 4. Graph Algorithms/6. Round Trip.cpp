#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector <int> ve[200005], v;
int par[200005], col[200005], ck = 0;

void dfs(int x) {
  col[x] = 1;
  for(int i = 0; i < ve[x].size(); i++) {
    if(col[ve[x][i]] == 1 and par[x] != ve[x][i] and ck == 0) {
      ck = 1;
      int u = x, ct = 0;
      v.push_back(u);
      while(u != ve[x][i]) {
        u = par[u];
        v.push_back(u);
      }
      v.push_back(x);
    }
    if(col[ve[x][i]] == 0) {
      par[ve[x][i]] = x;
      dfs(ve[x][i]);
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
    ve[b].push_back(a);
  }

  for(int i = 1; i <= n; i++) if(col[i] == 0) dfs(i);

  if(v.size() > 0) {
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++) cout << v[i] << ' ';
    cout << endl;
  }
  else {
    cout << "IMPOSSIBLE" << endl;
  }

  return 0;
}
