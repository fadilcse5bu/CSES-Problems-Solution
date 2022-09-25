#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

struct node {
  int col[200005];
  int level[200005];
} node;

void Set(int x) {
  for(int i = 0; i < 200005; i++) {
    node.col[i] = 0;
  }
  node.level[x] = 0;
}

vector <int> ve[200005];
int max_level = 1;
void dfs(int x) {
  node.col[x] = 1;
  for(int i = 0; i < ve[x].size(); i++) {
    if(node.col[ve[x][i]] == 0) {
      node.level[ve[x][i]] = node.level[x] + 1;
      if(node.level[max_level] < node.level[ve[x][i]]) max_level = ve[x][i];
      dfs(ve[x][i]);
    }
  }
}

int main()
{
  int n;
  cin >> n;
  for(int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    ve[a].push_back(b);
    ve[b].push_back(a);
  }

  Set(1);
  dfs(1);

  Set(max_level);
  dfs(max_level);

  cout << node.level[max_level] << endl;

  return 0;
}
