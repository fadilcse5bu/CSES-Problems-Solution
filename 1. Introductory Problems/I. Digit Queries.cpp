#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  ll q, k;
  cin >> q;
  while(q--) {
    cin >> k;
    ll len = 0, i = 0;
    while(1) {
      ++i;
      ll val = 9 * i * pow(10, i - 1);
      if(len + val >= k) break;
      len += val;
    }

    k -= len;
    ll num = pow(10, i - 1);
    ll ct = k / i;
    num += ct;
    if(k % i == 0) --num;
    k %= i;
    if(k == 0) k = i;

    vector <ll> ve;
    while(num > 0) {
      ll re = num % 10;
      ve.push_back(re);
      num /= 10;
    }
    reverse(ve.begin(), ve.end());
    cout << ve[k - 1] << endl;
  }

	return 0;
}
