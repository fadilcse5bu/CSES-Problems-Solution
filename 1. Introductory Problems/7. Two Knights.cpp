#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  ll n, ans = 0;
  cin >> n;
  for(ll i = 1; i <= n; i++) {
    ll v = (i * i * i * i - i * i) / 2, v1 = 4 * (i - 1) * (i - 2);
    ans = v - v1;
    cout << ans << endl;
  }

	return 0;
}
