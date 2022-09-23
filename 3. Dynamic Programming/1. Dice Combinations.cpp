#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll mod = 1000000007;
ll s[2000000], n, ans = 0;

ll dp(ll v) {
  if(v > n) return 0;
  if(v == n) return s[v] = 1;
  if(s[v] != 0) {
    return s[v];
  }

  ll c = 0;
  for(ll i = 1; i <= 6; i++) {
    c += (dp(v + i) % mod);
  }

  s[v] = c % mod;
  return s[v];
}

int main()
{
  //memset(s, -1, sizeof s);
  cin >> n;
  cout << dp(0) << endl;
  //for(int i = 1; i <= 6; i++) cout << s[i] << ' ';

	return 0;
}
