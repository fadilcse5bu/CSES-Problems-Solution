#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;

  vector <pair<pair<int, int>, int>> vp;
  vp.push_back({{0, 0}, 0});
  for(int i = 0; i < n; i++) {
    int a, b, p;
    cin >> a >> b >> p;
    vp.push_back({{b, a}, p});
  }

  sort(vp.begin(), vp.end());

  long int dp[n + 1] = {0};
  for(int i = 1; i <= n; i++) {
    int l = 0, r = n, indx = 0;
    while(l < r) {
      int mid = (l + r) / 2;
      if(vp[mid].first.first < vp[i].first.second){
        indx = mid;
        l = mid + 1;
      }
      else r = mid;
    }
    dp[i] = max(dp[i - 1], dp[indx] + vp[i].second);
  }

  cout << dp[n] << endl;

  return 0;
}
