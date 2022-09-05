#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  int n;
  cin >> n;
  map <int, int> mp;
  int ans = 0, mx = 0;
  for(int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    int in = mp[a];
    mx = max(mx, in);
    ans = max(ans, i - mx);
    mp[a] = i;
  }

  cout << ans << endl;

  return 0;
}
