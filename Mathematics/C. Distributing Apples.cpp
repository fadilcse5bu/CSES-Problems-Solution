#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll factorial[2000001], mod = 1e9 + 7;

void find_factorial() {
  factorial[0] = 1;
  for(ll i = 1; i < 2000001; i++) {
    factorial[i] = (factorial[i - 1] * i) % mod;
  }
}

ll inverse_module(ll b, ll p) {
  if(p == 0) return 1;
  if(p % 2 == 1) {
    return (b * inverse_module(b, p - 1)) % mod;
  }
  else {
    ll temp = inverse_module(b, p / 2);
    return (temp * temp) % mod;
  }
}

int main()
{
  ll n, m;
  cin >> n >> m;

  find_factorial();

  ll v1 = factorial[n + m - 1];
  ll v2 = (factorial[n - 1] * factorial[m]) % mod;

  ll ans = (v1 * inverse_module(v2, mod - 2)) % mod;
  cout << ans << endl;

  return 0;
}
