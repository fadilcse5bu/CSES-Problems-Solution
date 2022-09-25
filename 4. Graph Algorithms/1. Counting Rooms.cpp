#include<bits/stdc++.h>
using namespace std;
#define ll long long int

char ch[1005][1005];

void dp(int i, int j) {
  ch[i][j] = '#';
  if(ch[i + 1][j] == '.') dp(i + 1, j);
  if(ch[i][j + 1] == '.') dp(i, j + 1);
  if(ch[i - 1][j] == '.') dp(i - 1, j);
  if(ch[i][j - 1] == '.') dp(i, j - 1);
}

void Set(int n, int m) {
  for(int i = 0; i <= m + 1; i++) {
    ch[0][i] = '#';
    ch[n + 1][i] = '#';
  }
  for(int i = 0; i <= n + 1; i++) {
    ch[i][0] = '#';
    ch[i][m + 1] = '#';
  }
}

int main()
{
  int t = 1;
  //cin >> t;
  start:
  while(t--) {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= m; j++) {
        cin >> ch[i][j];
      }
    }
    Set(n, m);

    int ans = 0;
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= m; j++) {
        if(ch[i][j] == '.') {
          ++ans;
          dp(i, j);
        }
      }
    }

    cout << ans << endl;
  }

  return 0;
}
