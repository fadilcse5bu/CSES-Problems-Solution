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
  ll n;
  cin >> n;

  find_factorial();

  ll ans = factorial[n], sum = 0;
  for(ll i = 0; i <= n; i++) {
    ll v = inverse_module(factorial[i], mod - 2);
    if(i % 2 == 0) sum += v;
    else sum -= v;

    sum = (sum + mod) % mod;
  }

  ans = (ans * sum) % mod;

  cout << ans << endl;

  return 0;
}
