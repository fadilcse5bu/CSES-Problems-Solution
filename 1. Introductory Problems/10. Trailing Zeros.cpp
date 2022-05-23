#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  int n, v = 5, ans = 0;
  cin >> n;
  while(v <= n) {
    ans += (n / v);
    v *= 5;
  }
  cout << ans << endl;

	return 0;
}
