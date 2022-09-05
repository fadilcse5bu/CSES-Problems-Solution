#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>

int main()
{
  int n, k;
  cin >> n >> k;
  int ar[n];

  ordered_set os;

  for(int i = 0, j = 0; i < n; i++) {
    cin >> ar[i];
    os.insert({ar[i], i});
    if(i < k - 1) continue;

    auto I = os.find_by_order((k - 1) / 2);
    pair<int, int> p = *I;
    cout << p.first << ' ';

    p.first = ar[j];
    p.second = j;
    os.erase(os.find(p));
    ++j;
  }

  return 0;
}
