#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  int n, x;
  cin >> n >> x;
  map <int, int> mp;
  int a[n + 1];
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    mp[a[i]] = i;
  }

  for(int i = 1; i <= n; i++) {
    int v = x - a[i];
    if(mp[v] == i or mp[v] == 0) continue;
    else {
      cout << i << ' ' << mp[v] << endl;
      return 0;
    }
  }

  cout << "IMPOSSIBLE" << endl;

	return 0;
}
