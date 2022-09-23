#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int dp[1000005];

int main()
{
  int n, x;
  cin >> n >> x;
  int h[n], s[n];
  for(int i = 0; i < n; i++) cin >> h[i];
  for(int j = 0; j < n; j++) cin >> s[j];

  for(int i = 0; i < n; i++) {
    for(int j = x; j >= 0; j--) {
      if(j - h[i] >= 0) {
        dp[j] = max(dp[j], dp[j - h[i]] + s[i]);
      }
    }
  }

  cout << dp[x] << endl;

  return 0;
}
