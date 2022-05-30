#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  int t;
  cin >> t;
  while(t--) {
    ll a, b;
    cin >> a >> b;
    if(a * 2 < b or b * 2 < a or (a + b) % 3 != 0) cout << "NO" << endl;
    else cout << "YES" << endl;
  }

	return 0;
}
