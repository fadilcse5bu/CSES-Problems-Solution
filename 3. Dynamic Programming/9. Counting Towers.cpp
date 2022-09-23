#include <bits/stdc++.h>
using namespace std;
long int mod = 1e9 + 7;
long int dp[1000001][9];

int main()
{
  int t;
  cin >> t;

  for(int i = 1; i <= 8; i++) dp[0][i] = 1;
  for(int i = 1; i < 1000001; i++) {
    for(int j = 1; j <= 8; j++) {
      if(j == 1 or j == 2 or j == 5) {
        dp[i][j] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3]) % mod;
      }
      else {
        dp[i][j] = (dp[i - 1][4] + dp[i - 1][5] + dp[i - 1][6] + dp[i - 1][7] + dp[i - 1][8]) % mod;
      }
    }
  }

  while(t--) {
    long int n;
    cin >> n;
    long int ans = (dp[n - 1][2] + dp[n - 1][3]) % mod;
    cout << ans << endl;
  }


  return 0;
}
