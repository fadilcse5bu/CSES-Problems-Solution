#include<bits/stdc++.h>
using namespace std;
#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>

int main()
{
  int n;
  cin >> n;
  ordered_set os, os1;
  vector <tuple<int, int, int>> vt;
  for(int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    os.insert({y, i});
    os1.insert({y, i});
    y *= -1;
    vt.push_back({x, y, i});
  }

  sort(vt.begin(), vt.end());
  int contained[n], contains[n];
  for(int i = 0; i < n; i++) {
    auto [x, y, in] = vt[i];
    y *= -1;
    os.erase(os.find({y, in}));
    contained[in] = os.order_of_key({y, n});
  }

  for(int i = n - 1; i >= 0; i--) {
    auto [x, y, in] = vt[i];
    y *= -1;
    os1.erase(os1.find({y, in}));
    contains[in] = i - os1.order_of_key({y - 1, n});
  }

  for(int i = 0; i < n; i++) cout << contained[i] << ' ';
  cout << endl;
  for(int i = 0; i < n; i++) cout << contains[i] << ' ';

  return 0;
}
