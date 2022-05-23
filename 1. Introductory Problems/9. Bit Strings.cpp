#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  ll n, v = 5, ans = 1;
  cin >> n;
  for(ll i = 1; i <= n; i++) {
    ans *= 2;
    ans %= 1000000007;
  }
  cout << ans << endl;

	return 0;
}
