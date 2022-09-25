#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll mod = 1e9 + 7;

ll sum_all_divisors(ll num)
{
    ll sum = 0;
    for (ll i = 1; i <= sqrt(num); i++) {
        ll t1 = ((i%mod) * ((num / i - i + 1)%mod))%mod; // adding i every time it appears with numbers greater than or equal to itself
        ll a = num / i, b = num / i + 1;
        if(a % 2 == 0) a /= 2;
        else b /= 2;
        ll t2 = (((a%mod) * (b%mod))%mod - ((i * (i + 1)) / 2)%mod + mod) % mod; // adding numbers that appear with i and are greater than i
        sum = (sum + t1 + t2) % mod;
    }
    return sum;
}
int main()
{
    ll  n;
    cin >> n;
    ll sum = sum_all_divisors(n);
    cout << sum << '\n';
    return 0;
}
