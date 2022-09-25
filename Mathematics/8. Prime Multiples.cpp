#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod = 1e9 + 7;

int main()
{
  ll n, k;
  cin >> n >> k;
  ll prime_number[k+1];
  for(int i = 0; i < k; i++) {
    cin >> prime_number[i];
  }

  // using inclusion exclusion theory
  ll ans = 0;
  for(ll i = 1; i < (1 << k); i++) {
    ll cnt_interval = n, cnt_set = 0;
    for(ll j = 0; j < k; j++) {
      if(i & (1 << j)) {
        cnt_set++;
        cnt_interval /= prime_number[j];
      }
    }

    if(cnt_set % 2) {
      ans += cnt_interval;
    }
    else ans -= cnt_interval;
  }

  cout << ans << endl;


  return 0;
}
