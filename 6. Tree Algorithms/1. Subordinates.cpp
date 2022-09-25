#include <bits/stdc++.h>
using namespace std;

vector <int> ve[200005];
int sub[200005], par[200005];

void dfs(int x) {
  for(int i = 0; i < ve[x].size(); i++) {
    if(par[ve[x][i]] == 0) {
      par[ve[x][i]] = x;
      dfs(ve[x][i]);
    }
  }

  if(x != 1) {
    sub[par[x]] += (sub[x] + 1);
  }
}

int main()
{
  int n;
  cin >> n;
  for(int i = 2; i <= n; i++) {
    int a;
    cin >> a;
    ve[a].push_back(i);
  }

  par[1] = -1;
  dfs(1);

  for(int i = 1; i <= n; i++) cout << sub[i] << ' ';

  return 0;
}
