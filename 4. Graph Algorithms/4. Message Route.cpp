#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int n, m, par[100005];
vector <int> ve[100005];
bool col[100005];
queue <int> q;

void bfs() {
  while(!q.empty()) {
    int x = q.front();
    q.pop();
    for(int i = 0; i < ve[x].size(); i++) {
      if(col[ve[x][i]] == false) {
        q.push(ve[x][i]);
        par[ve[x][i]] = x;
        col[ve[x][i]] = true;
      }
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

  q.push(1);
  col[1] = true;
  bfs();

  if(par[n] == 0) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }

  vector <int> ans;
  ans.push_back(n);
  int child = n;
  while(par[child] > 0) {
    child = par[child];
    ans.push_back(child);
  }

  cout << ans.size() << endl;
  for(int i = ans.size() - 1; i >= 0; i--) {
    cout << ans[i] << ' ';
  }
  cout << endl;

  return 0;
}
