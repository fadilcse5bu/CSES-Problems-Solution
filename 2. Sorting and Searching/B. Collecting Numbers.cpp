#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  int n, m, a;
  cin >> n;
  int pos[n + 1];
  for(int i = 1; i <= n; i++) {
    cin >> a;
    pos[a] = i;
  }

  int ans = 1;
  for(int i = 1; i <= n; i++) {
    if(pos[i] < pos[i - 1]) ++ans;
  }

  cout << ans << endl;

  return 0;
}
