#include<bits/stdc++.h>
using namespace std;
#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>


int main()
{
  ll n, k;
  cin >> n >> k;
  ordered_set os;
  for(int i = 1; i <= n; i++) os.insert(i);
  ll in = 0;
  for(int i = n; i >= 1; i--) {
    in = (in + k) % i;
    auto v = os.find_by_order(in);
    os.erase(*v);
    cout << *v <<  ' ';
  }

  return 0;
}
