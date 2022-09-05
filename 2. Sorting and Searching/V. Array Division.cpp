#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;
  long int ar[n], sum = 0, mx = 0;
  for(int i = 0; i < n; i++) {
    cin >> ar[i];
    sum += ar[i];
    mx = max(mx, ar[i]);
  }

  long int l = mx, r = sum;
  while(l < r) {
    long int d = l + (r- l + 1) / 2;

    long int s = 0, ct = 1;
    bool ck = false;
    for(int i = 0; i < n; i++) {
      s += ar[i];
      if(s >= d) {
        ++ct;
        s = ar[i];
      }
    }
    if(ct > k) {
      l = d;
    }
    else {
      if(r == d) break;
      r = d;
    }
  }

  cout << l << endl;


  return 0;
}
