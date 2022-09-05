#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  int n, k;
  cin >> n >> k;
  int x[n], dist = 1, pos = 0;
  for(int i = 0; i < n; i++) cin >> x[i];
  map <int, int> curr;
  curr[x[0]] = 1;
  ll ans = 1;
  for(int i = 1; i < n; i++) {
    if(curr[x[i]] == 0) {
      dist++;
    }
    curr[x[i]]++;
    while(dist > k) {
      curr[x[pos]]--;
      if(curr[x[pos]] == 0) dist--;
      pos++;
    }
    ans += (i - pos + 1);
  }

  cout << ans << endl;

	return 0;
}
