#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  int t;
  cin >> t;
  while(t--) {
    ll x, y;
    cin >> x >> y;
    ll mx = max(x, y);
    ll lw = (mx - 1) * (mx - 1) + 1, hw = mx * mx, ans;
    if(mx & 1) {
      if(x == mx) {
        ans = lw + (y - 1);
      }
      else {
        ans = hw - x + 1;
      }
    }
    else {
      if(x == mx) {
        ans = hw - y + 1;
      }
      else {
        ans = lw + x - 1;
      }
    }
    cout << ans << endl;
  }

	return 0;
}
