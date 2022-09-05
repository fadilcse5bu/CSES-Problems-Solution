#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long int n, x, ans = 0, sum = 0;
  cin >> n >> x;
  map <long long int, int> mp;
  mp[0] = 1;
  for(int i = 1; i <= n; i++) {
    long long int a;
    cin >> a;
    sum += a;
    mp[sum] = 1;
    if(sum >= x) ans += mp[sum - x];
  }

  cout << ans << endl;

  return 0;
}
/*
5 7
2 4 1 2 7
*/
