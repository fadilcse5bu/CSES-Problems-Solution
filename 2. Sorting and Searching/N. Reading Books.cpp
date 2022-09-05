#include <bits/stdc++.h>
using namespace std;
long int mod = 1e9 + 7;
long int dp[1000001][2];

int main()
{
  int n;
  cin >> n;
  long int sum = 0, mx = 0;
  for(int i = 0; i < n; i++) {
    long int t;
    cin >> t;
    sum += t;
    mx = max(mx, t);
  }

  long int ans = sum;
  sum -= mx;
  if(sum < mx) {
    ans += (mx - sum);
  }

  cout << ans << endl;


  return 0;
}
