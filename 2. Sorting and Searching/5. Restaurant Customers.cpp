#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  int n;
  cin >> n;
  vector <pair<int, int>> vp;
  for(int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    vp.push_back({a, 1});
    vp.push_back({b, -1});
  }

  sort(vp.begin(), vp.end());
  int ans = 0, sum = 0;
  for(int i = 0; i < vp.size(); i++) {
    sum += vp[i].second;
    ans = max(ans, sum);
  }

  cout << ans << endl;

	return 0;
}
