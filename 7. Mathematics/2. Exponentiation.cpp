#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int bigMod(int b, int p) {
  if(p == 0) return 1;
  if(p % 2 == 1) return (int64_t(b) * int64_t(bigMod(b, p - 1)) % mod);
  else {
    int temp = bigMod(b, p / 2);
    return (int64_t(temp) * int64_t(temp)) % mod;
  }
}

int main()
{
  int n;
  cin >> n;
  while(n--) {
    int a, b;
    cin >> a >> b;
    int ans = bigMod(a, b);
    cout << ans << endl;
  }

  return 0;
}
