#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
  int n;
  cin >> n;
  ll ar[n], ans = 0;
  for(int i = 0; i < n; i++) cin >> ar[i];

  sort(ar, ar + n);
  for(int i = 0; i < n; i++) {
    if(ar[i] > ans + 1) break;
    ans += ar[i];
  }

  cout << ans + 1 << endl;

  return 0;
}
