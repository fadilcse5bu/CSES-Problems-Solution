#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int n, m, par[100005], ck = 1;
vector <int> ve[100005];
bool col[100005];
queue <int> q;

void bfs() {
  while(!q.empty()) {
    int x = q.front();
    q.pop();
    for(int i = 0; i < ve[x].size(); i++) {
      if(par[x] == par[ve[x][i]]) ck = -1;
      else {
        if(par[ve[x][i]] == 0) {
          q.push(ve[x][i]);
          if(par[x] == 1) par[ve[x][i]] = 2;
          else par[ve[x][i]] = 1;
        }
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
  for(int i = 1; i <= n; i++) {
    if(par[i] == 0) {
      par[i] = 1;
      q.push(i);
      bfs();
    }
  }

  if(ck == -1) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }

  for(int i = 1; i <= n; i++) cout << par[i] << ' ';

  return 0;
}
