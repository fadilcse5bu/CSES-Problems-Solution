#include <bits/stdc++.h>
using namespace std;

bool chk[1000005];

int main()
{
  int n, x, ans = 1;
  cin >> n;
  while(n--) {
    cin >> x;
    int sr = sqrt(x);
    for(int i = 1; i <= sr; i++) {
      if(x % i == 0) {
        if(chk[i]) ans = max(ans, i);
        if(chk[x / i]) ans = max(ans, x / i);
        chk[i] = 1;
        chk[x / i] = 1;
      }
    }
  }
  cout << ans << endl;

  return 0;
}
