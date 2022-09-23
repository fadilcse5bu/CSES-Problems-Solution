#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll dp[100005][105], mod = 1000000007;

int main()
{
  ll n, m;
  cin >> n >> m;
  for(int i = 0; i <= n + 1; i++) {
    for(int j = 0; j <= m + 1; j++) {
      dp[i][j] = 0;
    }
  }

  ll ar[n + 1], ans = 0;
  cin >> ar[1];
  if(ar[1] != 0) dp[1][ar[1]] = 1;
  else {
    for(int j = 1; j <= m; j++) dp[1][j] = 1;
  }
  for(int i = 2; i <= n; i++) {
    cin >> ar[i];
    if(ar[i] != 0) {
      dp[i][ar[i]] += dp[i - 1][ar[i] - 1];
      dp[i][ar[i]] += dp[i - 1][ar[i]];
      dp[i][ar[i]] += dp[i - 1][ar[i] + 1];

      dp[i][ar[i]] %= mod;
      if(i == 1) {
        dp[i][ar[i]] = 1;
      }
    }
    else {
      for(ll j = 1; j <= m; j++) {
        dp[i][j] += dp[i - 1][j - 1];
        dp[i][j] += dp[i - 1][j];
        dp[i][j] += dp[i - 1][j + 1];

        dp[i][j] %= mod;
      }
    }
  }

  if(ar[n] == 0) {
    for(ll j = 1; j <= m; j++) {
      ans += dp[n][j];
      ans %= mod;
    }
  }
  else ans = dp[n][ar[n]];

  cout << ans << endl;

	return 0;
}
