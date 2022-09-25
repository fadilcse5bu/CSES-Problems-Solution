#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  while(n--) {
    int x, ans = 0;
    cin >> x;
    for(int i = 1; i <= sqrt(x); i++) {
      if(x % i == 0) {
        ans += 2;
        if(i == (x / i)) --ans;
      }
    }

    cout << ans << endl;
  }

  return 0;
}
