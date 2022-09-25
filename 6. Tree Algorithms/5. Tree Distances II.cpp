#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int n, node[200005], col[200005], par[200005];
ll ans[200005], dis[200005];

vector <int> ve[200005];

void dfs(int x) {
  col[x] = 1;
  for(int i = 0; i < ve[x].size(); i++) {
    if(col[ve[x][i]] == 0) {
      par[ve[x][i]] = x;
      dfs(ve[x][i]);
    }
  }

  ll v = 0, nd = 0;
  for(int i = 0; i < ve[x].size(); i++) {
    if(par[x] != ve[x][i]) {
      v += (node[ve[x][i]] + dis[ve[x][i]]);
      nd += node[ve[x][i]];
    }
  }
  node[x] = nd + 1;
  dis[x] = v;
}


int cl[200005];
void dfs_again(int x) {
  cl[x] = 1;
  for(int i = 0; i < ve[x].size(); i++) {
    if(cl[ve[x][i]] == 0) {
      ll v = ans[x] - dis[ve[x][i]] - node[ve[x][i]] + n - node[ve[x][i]];
      ans[ve[x][i]] = v + dis[ve[x][i]];

      dfs_again(ve[x][i]);
    }
  }
}

int main()
{
  cin >> n;
  for(int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    ve[a].push_back(b);
    ve[b].push_back(a);
  }

  dfs(1);
  ans[1] = dis[1];
  dfs_again(1);

  for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
  cout << endl;

  return 0;
}
