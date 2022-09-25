#include<bits/stdc++.h>
using namespace std;

int nodes, mxdis[200005][2], fNode[200005][2];
int ans[200005], col[200005], par[200005];
vector <int> ve[200005];

void set_value() {
  for(int i = 0; i <= 200001; i++) {
    mxdis[i][0] = 0;
    mxdis[i][1] = 0;
    fNode[i][0] = -1;
    fNode[i][1] = -1;
  }
}

void dfs(int x) {
  col[x] = 1;
  for(int i = 0; i < ve[x].size(); i++) {
    if(col[ve[x][i]] == 0) {
      par[ve[x][i]] = x;
      dfs(ve[x][i]);
    }
  }

  for(int i = 0; i < ve[x].size(); i++) {
    if(ve[x][i] == x or par[x] == ve[x][i]) continue;
    int v = mxdis[ve[x][i]][0] + 1;
    if(v > mxdis[x][0]) {
      mxdis[x][1] = mxdis[x][0];
      fNode[x][1] = fNode[x][0];
      mxdis[x][0] = v;
      fNode[x][0] = ve[x][i];
    }
    else if(v > mxdis[x][1]) {
      mxdis[x][1] = v;
      fNode[x][1] = ve[x][i];
    }
  }
}


int cl[200005];
void dfs_again(int x) {
  cl[x] = 1;
  for(int i = 0; i < ve[x].size(); i++) {
    if(cl[ve[x][i]] == 0) {
      int v1 = mxdis[ve[x][i]][0], v2, vv;
      if(fNode[x][0] != ve[x][i]) v2 = mxdis[x][0] + 1;
      else v2 = mxdis[x][1] + 1;
      ans[ve[x][i]] = max(v1, v2);

      if(v2 > mxdis[ve[x][i]][0]) {
        mxdis[ve[x][i]][1] = mxdis[ve[x][i]][0];
        fNode[ve[x][i]][1] = fNode[ve[x][i]][0];
        mxdis[ve[x][i]][0] = v2;
        fNode[ve[x][i]][0] = x;
      }
      else if(v2 > mxdis[ve[x][i]][1]) {
        mxdis[ve[x][i]][1] = v2;
        fNode[ve[x][i]][1] = x;
      }

      dfs_again(ve[x][i]);
    }
  }
}

int main()
{
  int nodes;
  cin >> nodes;
  for(int i = 1; i < nodes; i++) {
    int a, b;
    cin >> a >> b;
    ve[a].push_back(b);
    ve[b].push_back(a);
  }

  set_value();
  dfs(1);
  ans[1] = mxdis[1][0];

  dfs_again(1);


  for(int i = 1; i <= nodes; i++) cout << ans[i] << ' ';
  cout << endl;

  return 0;
}
