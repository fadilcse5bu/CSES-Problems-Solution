#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll mod = 1000000007;

int main()
{
  int n;
  cin >> n;
  int v = (n * (n + 1)) / 2;

  if(v % 2) {
    cout << 0 << endl;
    return 0;
  }

  v /= 2;

  ll dp[v + 1] = {0};
  dp[0] = 1;
  for(int i = 1; i < n; i++) {
    for(int j = v; j >= i; j--) {
      dp[j] += dp[j - i];
      dp[j] %= mod;
    }
  }

  cout << dp[v] << endl;

  return 0;
}
