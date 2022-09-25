#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int n, m;
vector <int> ve[100005];
bool col[100005];

void dfs(int x) {
  col[x] = true;
  for(int i = 0; i < ve[x].size(); i++) {
    if(col[ve[x][i]] == false) {
      dfs(ve[x][i]);
    }
  }
}

int main()
{
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    ve[a].push_back(b);
    ve[b].push_back(a);
  }

  int pre = -1;
  vector <pair<int, int>> ans;
  for(int i = 1; i <= n; i++) {
    if(col[i] == false) {
      dfs(i);
      if(pre != -1) ans.push_back({pre, i});
      pre = i;
    }
  }

  cout << ans.size() << endl;
  for(int i = 0; i < ans.size(); i++) {
    cout << ans[i].first << ' ' << ans[i].second << endl;
  }


  return 0;
}
