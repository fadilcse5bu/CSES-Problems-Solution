#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int dp[1000005];

int main()
{
  int n, x, c;
  cin >> n >> x;
  dp[0] = 1;

  while(n--) {
    cin >> c;
    for(int i = c; i <= x; i++) {
      dp[i] += dp[i - c];
      dp[i] %= mod;
    }
  }

  cout << dp[x] << endl;

  return 0;
}
