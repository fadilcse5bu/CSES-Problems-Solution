#include <bits/stdc++.h>
using namespace std;

int col[200005], parent[200005], node, maximum_number_of_pair = 0, taken[200005];
vector <int> ve[200005];

void dfs(int x) {
  col[x] = 1;
  for(int i = 0; i < ve[x].size(); i++) {
    parent[ve[x][i]] = x;
    if(col[ve[x][i]] == 0) dfs(ve[x][i]);
  }

  for(int i = 0; i < ve[x].size(); i++) {
    if(taken[x] == 0 and taken[ve[x][i]] == 0) {
      ++maximum_number_of_pair;
      taken[x] = 1;
      taken[ve[x][i]] = 1;
    }
  }
}

int main()
{
  cin >> node;
  for(int i = 1; i < node; i++) {
    int a, b;
    cin >> a >> b;
    ve[a].push_back(b);
    ve[b].push_back(a);
  }

  dfs(1);

  cout << maximum_number_of_pair << endl;

  return 0;
}
