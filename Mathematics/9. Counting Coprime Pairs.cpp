#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ct[1000005];
bool ck[1000005];

vector <ll> pr;
void sieve()
{
  pr.push_back(2);
  for(ll i = 3; i*i <= 1000001; i += 2) {
    if(ck[i] == 0) {
      for(ll j = i*i; j * j <= 1000001; j += i) {
        ck[j] = 1;
      }
    }
  }

  for(ll i = 3; i <= 1000001; i += 2) {
    if(ck[i] == 0) pr.push_back(i);
  }
}

int main()
{
  memset(ct, 0, sizeof(ct));
  sieve();
  ll n;
  cin >> n;
  ll num[n], cnt = 0;
  for(int i = 0; i < n; i++) {
    cin >> num[i];
    vector <ll> prime;
    ll sq = sqrt(num[i]);
    for(ll j = 0; ;j++) {
      if(pr[j] > sq) break;
      if(num[i] % pr[j] != 0) continue;
      prime.push_back(pr[j]);
      while(num[i] % pr[j] == 0) {
        num[i] /= pr[j];
      }
    }
    if(num[i] != 1) prime.push_back(num[i]);

    ll sz = prime.size();
    // using inclusion exclusion theory
    for(ll j = 1; j < (1 << sz); j++) {
      ll lcm = 1, c = 0;
      for(ll k = 0; k < sz; k++) {
        if(j & (1 << k)) {
          ++c;
          lcm *= prime[k];
        }
      }
      if(c % 2 == 1) cnt += ct[lcm];
      else cnt -= ct[lcm];
      ct[lcm]++;
    }
  }

  ll ans = (n * (n-1)) / 2 - cnt;
  cout << ans << endl;

  return 0;
}
