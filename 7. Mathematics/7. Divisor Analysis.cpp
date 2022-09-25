#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod = 1e9 + 7;

ll pow_cal(ll base, ll power) {
  if(power == 0) return 1;
  if(power % 2 == 1) return (base*(pow_cal(base, power - 1)))%mod;
  else {
    ll temp = pow_cal(base, power/2);
    return (temp*temp)%mod;
  }
}

int main()
{
  ll nn = 12;

  ll n;
  cin >> n;
  ll prime_number[n], power[n];
  ll number_of_divisors = 1;
  ll sum_of_divisors = 1;
  ll num = 1, sq_num = 1;

  bool ck = false;
  for(int i = 0; i < n; i++) {
    cin >> prime_number[i] >> power[i];
    if(power[i] % 2 == 0) {
      sq_num = (sq_num * pow_cal(prime_number[i], power[i] / 2)) % mod;
    }
    else ck = true;
    ++power[i];

    ll v = pow_cal(prime_number[i], power[i]-1);
    num = (num * v) % mod;

    number_of_divisors = (number_of_divisors * power[i]) % mod;

    ll numerator = (pow_cal(prime_number[i], power[i]) - 1 + mod)%mod;
    ll denominator = pow_cal(prime_number[i] - 1, mod - 2);
    sum_of_divisors = ((((sum_of_divisors * numerator)%mod) * denominator)%mod)%mod;
  }

  ll product_of_divisors = sq_num;
  if(ck == true) {
    product_of_divisors = num;
    for(int i = 0; i < n; i++) {
      if(power[i] % 2 == 0) {
        power[i] /= 2;
        break;
      }
    }
  }

  for(int i = 0; i < n; i++) {
    product_of_divisors = pow_cal(product_of_divisors, power[i]) % mod;
  }

  cout << number_of_divisors << " " << sum_of_divisors << ' ' << product_of_divisors << endl;


  return 0;
}
