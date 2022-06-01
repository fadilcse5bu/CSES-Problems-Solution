#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  int n, ans = 0;
  cin >> n;
  map <int, int> mp;
  while(n--) {
    int a;
    cin >> a;
    if(mp[a] == 0) {
      ++ans;
      mp[a] = 1;
    }
  }

  cout << ans << endl;

	return 0;
}
