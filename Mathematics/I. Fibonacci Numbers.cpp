#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll b0 = 0, b1 = 1, b2 = 1, mod = 1e9 + 7;
ll f0 = 0, f1 = 1, f2 = 1;

void nth_fibonacci_number(ll n) {
  if(n <= 1) return;
  if(n % 2 == 0) {
    nth_fibonacci_number(n / 2);
    ll t0 = f0, t1 = f1, t2 = f2;
    f0 = (t1 * t1 + t0 * t0) % mod;
    f1 = (t2 * t1 + t1 * t0) % mod;
    f2 = (t2 * t2 + t1 * t1) % mod;
  }
  else {
    nth_fibonacci_number(n - 1);
    ll t0 = f0, t1 = f1, t2 = f2;
    f0 = (t1 * b1 + t0 * b0) % mod;
    f1 = (t2 * b1 + t1 * b0) % mod;
    f2 = (t2 * b2 + t1 * b1) % mod;
  }
}

int main()
{
  ll n;
  cin >> n;

  nth_fibonacci_number(n - 1);
  if(n == 0) f2 = 0;
  cout << f2 << endl;

  return 0;
}


/*
1 1   1 1
1 0   1 0
f2 f1   f2 f1
f1 f0   f1 f0

(f2 * f2 + f1 * f1)  (f2 * f1 + f1 * f0)
(f1 * f2 + f0 * f1)  (f1 * f1 + f0 * f0)
*/
