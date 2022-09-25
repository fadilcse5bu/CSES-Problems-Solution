#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll len[501][501];

void fw(int n) {
  for(int k = 1; k <= n; k++) {
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        len[i][j] = min(len[i][j], len[i][k] + len[k][j]);
      }
    }
  }
}

int main()
{
  int n, m, q;
  cin >> n >> m >> q;
  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= n; j++) {
      len[i][j] = 1e18;
      if(i == j) len[i][j] = 0;
    }
  }

  for(int i = 0; i < m; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    len[a][b] = min(c, len[a][b]);
    len[b][a] = min(c, len[b][a]);
  }

  fw(n);

  while(q--) {
    int a, b;
    cin >> a >> b;
    if(len[a][b] == 1e18) cout << -1 << endl;
    else cout << len[a][b] << endl;
  }

  return 0;
}
