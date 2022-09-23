#include<bits/stdc++.h>
using namespace std;
#define ll long long int



int main()
{
  string x, y;
  cin >> x >> y;
  int n = x.size(), m = y.size();
  int dp[n + 1][m + 1];
  for(int i = 0; i <= n; i++) {
    dp[i][0] = i;
  }
  for(int j = 0; j <= m; j++) {
    dp[0][j] = j;
  }

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      int mn = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]);
      if(x[i - 1] == y[j - 1]) dp[i][j] = dp[i - 1][j - 1];
      else dp[i][j] = mn + 1;
    }
  }

  cout << dp[n][m] << endl;

	return 0;
}
