#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long int n, x, sum = 0, ans = 0;
  cin >> n >> x;
  map <long long int, int> mp;
  mp[0] = 1;
  for(int i = 1; i <= n; i++) {
    long long int a;
    cin >> a;
    sum += a;
    ans += mp[sum - x];
    ++mp[sum];
  }

  cout << ans << endl;

  return 0;
}
