#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector <int> ve[100005], sorted_order;
int s = 0, col[100005], f_time[100005], cur[100005];
bool ck = false;

void dfs(int x) {
  cur[x] = 1;
  col[x] = 1;
  s++;
  for(int i = 0; i < ve[x].size(); i++) {
    if(cur[ve[x][i]] == 1) {
      ck = true;
    }
    if(col[ve[x][i]] == 0) dfs(ve[x][i]);
  }
  f_time[x] = s;
  cur[x] = 0;
}

void dfs_again(int x) {
  col[x] = 1;
  for(int i = 0; i < ve[x].size(); i++) {
    if(col[ve[x][i]] == 0) dfs_again(ve[x][i]);
  }
  sorted_order.push_back(x);
}

int main()
{
  int n, m;
  cin >> n >> m;
  while(m--) {
    int a, b;
    cin >> a >> b;
    ve[b].push_back(a);
  }

  for(int i = 1; i <= n; i++) {
    if(col[i] == 0) {
      dfs(i);
    }
  }

  if(ck == true) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }

  vector <pair<int, int>> vp;
  for(int i = 1; i <= n; i++) {
    col[i] = 0;
    vp.push_back({f_time[i], i});
  }
  sort(vp.rbegin(), vp.rend());

  for(int i = 0; i < vp.size(); i++) {
    if(col[vp[i].second] == 0) {
      dfs_again(vp[i].second);
    }
  }

  for(int i = 0; i < sorted_order.size(); i++) {
    cout << sorted_order[i] << ' ';
  }
  cout << endl;

  return 0;
}
