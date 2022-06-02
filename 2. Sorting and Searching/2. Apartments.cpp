#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  ll n, m, k;
  cin >> n >> m >> k;
  ll a[n], b[m];
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < m; i++) cin >> b[i];
  sort(a, a + n);
  sort(b, b + m);

  int i = 0, j = 0, ans = 0;
  while(i < n and j < m) {
    if(a[i] >= (b[j] - k) and a[i] <= (b[j] + k)) {
      ++ans;
      ++i, ++j;
    }
    else if(a[i] < b[j]) ++i;
    else ++j;
  }

  cout << ans << endl;

	return 0;
}
