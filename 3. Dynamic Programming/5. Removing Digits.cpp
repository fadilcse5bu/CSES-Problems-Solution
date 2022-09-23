#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int dp[1000005];

int main()
{
  int n;
  cin >> n;
  dp[0] = 0;
  for(int i = 1; i <= n; i++) {
    int num = i, mn = INT_MAX;
    while(num > 0) {
      int re = num % 10;
      num /= 10;
      if(re > 0) {
        mn = min(mn, dp[i - re]);
      }
    }
    dp[i] = mn + 1;
  }

  cout << dp[n] << endl;

	return 0;
}
