#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll factorial[1000001], mod = 1e9 + 7;

void find_factorial() {
  factorial[0] = 1;
  for(ll i = 1; i < 1000001; i++) {
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
  string st;
  cin >> st;
  ll length = st.size(), cnt_char[27] = {0};
  for(int i = 0; i < length; i++) {
    int indx = st[i] - 'a';
    cnt_char[indx]++;
  }

  find_factorial();

  ll v1 = factorial[length], v2 = 1;
  for(int i = 0; i < 26; i++) {
    v2 = (v2 * factorial[cnt_char[i]]) % mod;
  }

  ll ans = (v1 * inverse_module(v2, mod - 2)) % mod;
  cout << ans << endl;

  return 0;
}
