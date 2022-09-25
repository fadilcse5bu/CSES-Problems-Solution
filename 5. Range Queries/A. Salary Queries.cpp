#include <bits/stdc++.h>
using namespace std;
#define ll long long in

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree <pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>

int main()
{
  int n, q;
  cin >> n >> q;
  ordered_set o_set;
  int ar[n + 1];
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
    o_set.insert({ar[i], i});
  }


  while(q--) {
    char ch;
    cin >> ch;
    int a, b;
    cin >> a >> b;
    if(ch == '?') {
      int ans = o_set.order_of_key({b, n + 1}) - o_set.order_of_key({a - 1, n + 1});
      cout << ans << endl;
    }
    else {
      o_set.erase(o_set.find({ar[a], a}));
      o_set.insert({b, a});
      ar[a] = b;
    }
  }

  return 0;
}
