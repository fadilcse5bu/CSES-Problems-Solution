#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int main()
{
  int n;
  cin >> n;
  int dp[n][n];
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      dp[i][j] = 0;
    }
  }

  char car[n][n];
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> car[i][j];
    }
  }
  if(car[0][0] == '.') dp[0][0] = 1;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(car[i][j] == '*') continue;
      if(i < n - 1 and car[i + 1][j] == '.') {
        dp[i + 1][j] += (dp[i][j]);
        dp[i + 1][j] %= mod;
      }
      if(j < n - 1 and car[i][j + 1] == '.') {
        dp[i][j + 1] += (dp[i][j]);
        dp[i][j + 1] %= mod;
      }
    }
  }

  cout << dp[n - 1][n - 1] << endl;

  return 0;
}
