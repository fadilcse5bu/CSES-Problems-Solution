#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  long long ans = 0, pref = 0;
  map <long long, long long> mp;
  mp[0] = 1;
  for(int i = 0; i < n; i++) {
    long long a;
    cin >> a;
    pref = (((pref + a) % n) + n) % n;
    ans += mp[pref];
    mp[pref]++;
  }

  cout << ans << endl;


  return 0;
}
