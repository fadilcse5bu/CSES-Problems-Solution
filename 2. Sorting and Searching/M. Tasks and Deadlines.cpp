#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector <pair<int, int>> vp;
  while(n--) {
    int a, b;
    cin >> a >> b;
    vp.push_back({a, b});
  }

  sort(vp.begin(), vp.end());
  long int sum = 0, ans = 0;
  for(int i = 0; i < vp.size(); i++) {
    sum += vp[i].first;
    ans += (vp[i].second - sum);
  }

  cout << ans << endl;

  return 0;
}
