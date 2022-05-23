#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  ll n;
  cin >> n;
  ll v = (n * (n + 1)) / 2;
  if(v % 2 == 1) {
    cout << "NO" << endl;
    return 0;
  }

  v /= 2;
  map <ll, ll> mp;
  vector <ll> ve;
  for(ll i = n; i > 0; i--) {
    if(v - i >= 0) {
      v -= i;
      ve.push_back(i);
      mp[i] = 1;
    }
  }
  cout << "YES" << endl << ve.size() << endl;
  for(int i = ve.size() - 1; i >= 0; i--) cout << ve[i] << ' ';
  cout << endl << n - ve.size() << endl;
  for(ll i = 1; i <= n; i++) if(mp[i] == 0) cout << i << ' ';
  cout << endl;

	return 0;
}
