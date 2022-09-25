#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll fact[1000005], m = 1e9 + 7;
void find_factorial() {
  fact[0] = 1;
  for(ll i = 1; i <= 1000001; i++) {
    fact[i] = (fact[i - 1] * i) % m;
  }
}

ll inverse_module(ll a, ll p) {
  if(p == 0) return 1;
  if(p % 2) return (a * inverse_module(a, p - 1)) % m;
  else {
    ll temp = inverse_module(a, p / 2);
    return (temp * temp) % m;
  }
}

int main()
{
  find_factorial();
  int n;
  cin >> n;
  while(n--) {
    ll a, b;
    cin >> a >> b;
    b = (fact[b] * fact[a - b]) % m;
    a = fact[a];
    ll ans = (a * inverse_module(b, m - 2)) % m;
    cout << ans << endl;
  }

  return 0;
}
