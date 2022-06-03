#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  int n;
  cin >> n;
  vector <pair<int, int>> vp;
  vector <int> v;
  for(int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    vp.push_back({b, a});
    v.push_back(b);
  }

  vp.push_back({0, 0});
  v.push_back(0);
  sort(v.begin(), v.end());
  sort(vp.begin(), vp.end());

  int ct[n + 1];
  ct[0] = 0;

  int ans = 0;
  for(int i = 1; i < vp.size(); i++) {
    auto I = lower_bound(v.begin(), v.end(), vp[i].second);
    int in = I - v.begin();
    if(v[in] != vp[i].second) --in;
    ct[i] = max(ct[i - 1], ct[in] + 1);
    ans = max(ans, ct[i]);
  }

  cout << ans << endl;

	return 0;
}
