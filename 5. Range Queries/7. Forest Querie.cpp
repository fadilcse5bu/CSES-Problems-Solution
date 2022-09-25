#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  int n, q;
  cin >> n >> q;
  int dp[n + 1][n + 1];
  for(int i = 0; i <= n; i++)
    for(int j = 0; j <= n; j++) dp[i][j] = 0;

  for(int i = 1; i <= n; i++) {
    string st;
    cin >> st;
    int ct = 0;
    for(int j = 1; j <= n; j++) {
      if(st[j - 1] == '*') ++ct;
      dp[i][j] = dp[i - 1][j] + ct;
    }
  }

  while(q--) {
    int y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2;
    int ans = dp[y2][x2] - dp[y1 - 1][x2] - dp[y2][x1 - 1] + dp[y1 - 1][x1 - 1];
    cout << ans << endl;
  }


  return 0;
}
