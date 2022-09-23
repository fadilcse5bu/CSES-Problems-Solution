#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  int n, x, mod = 1000000007;
  scanf("%d %d", &n, &x);
  int ar[n], dp[x + 1] = {0};
  for(int i = 0; i < n; i++) scanf("%d", &ar[i]);

  dp[0] = 1;
  for(int i = 1; i <= x; i++) {
    for(int j = 0; j < n; j++) {
      if(i - ar[j] >= 0) {
        dp[i] = (dp[i] + dp[i - ar[j]]) % mod;
      }
    }
  }

  cout << dp[x] << endl;

	return 0;
}
