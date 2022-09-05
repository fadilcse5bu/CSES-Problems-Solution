#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  int n;
  cin >> n;
  vector <pair<pair<int, int>, int>> v;
  for(int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    b *= -1;
    v.push_back({{a, b}, i});
  }

  sort(v.begin(), v.end());
  bool ans[n], ans1[n];
  int mn = 1e9 + 7;
  for(int i = n - 1; i >= 0; i--) {
    int b = v[i].first.second, c = v[i].second;
    b *= -1;
    if(b >= mn) {
      ans[c] = 1;
    }
    else ans[c] = 0;
    mn = min(mn, b);
  }

  int mx = 0;
  for(int i = 0; i < n; i++) {
    int b = v[i].first.second, c = v[i].second;
    b *= -1;
    if(b <= mx) {
      ans1[c] = 1;
    }
    else ans1[c] = 0;
    mx = max(mx, b);
  }

  for(int i = 0; i < n; i++) cout << ans[i] << ' ';
  cout << endl;
  for(int i = 0; i < n; i++) cout << ans1[i] << ' ';
  cout << endl;

  return 0;
}
