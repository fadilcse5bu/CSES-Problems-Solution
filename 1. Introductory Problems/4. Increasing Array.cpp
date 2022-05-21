#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  ll n, ans = 0, pre, a;
  cin >> n >> a;
  pre = a;
  for(int i = 1; i < n; i++) {
    cin >> a;
    if(a < pre) ans += (pre - a);
    else pre = a;
  }
  cout << ans << endl;
	return 0;

}
