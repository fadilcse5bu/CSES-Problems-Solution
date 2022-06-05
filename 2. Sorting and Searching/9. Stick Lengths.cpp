#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  ll n, sum = 0;
  cin >> n;
  ll a[n];
  for(int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for(int i = 0; i < n; i++) {
    sum += (a[i] - a[0]);
  }

  ll ans = sum;
  for(ll i = 1; i < n; i++) {
    ll d = a[i] - a[i - 1];
    sum = sum - (d * (n - i));
    sum = sum + (d * i);
    ans = min(ans, sum);
  }

  cout << ans << endl;

	return 0;
}
