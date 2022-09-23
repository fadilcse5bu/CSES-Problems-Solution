#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll mod = 1000000007;
ll s[2000000], n, v, ar[200];

void dp(ll sum, ll ct) {
  for(ll i = n - 1; i >= 0; i--) {
    ll val = sum + ar[i];
    if(val > v) continue;
    if(s[val] != -1 and s[val] <= ct + 1) continue;
    s[val] = ct + 1;
    dp(val, ct + 1);
  }
}

int main()
{
  memset(s, -1, sizeof s);
  cin >> n >> v;
  for(int i = 0; i < n; i++) {
    cin >> ar[i];
  }
  sort(ar, ar + n);
  dp(0, 0);

  cout << s[v] << endl;

	return 0;
}
