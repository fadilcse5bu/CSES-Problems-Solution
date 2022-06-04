#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  ll n, sum, ans;
  cin >> n;
  ll a;
  cin >> a;
  sum = a;
  if(sum < 0) sum = 0;
  ans = a;
  for(int i = 1; i < n; i++) {
    ll a;
    cin >> a;
    sum += a;
    ans = max(ans, sum);
    if(sum < 0) sum = 0;
  }

  cout << ans << endl;

	return 0;
}
