#include <bits/stdc++.h>
using namespace std;

long long int mod = 1e9 + 7;

int bigMod(long long int b, long long int p, long long int md) {
  if(p == 0) return 1;
  if(p % 2 == 1) return (b * bigMod(b, p - 1, md) % md);
  else {
    long long int temp = bigMod(b, p / 2, md);
    return (temp * temp) % md;
  }
}

int main()
{
  int n;
  cin >> n;
  while(n--) {
    long long int a, b, c;
    cin >> a >> b >> c;
    long long int bc = bigMod(b, c, mod - 1);
    long long int abc = bigMod(a, bc, mod);
    cout << abc << endl;
  }

  return 0;
}
