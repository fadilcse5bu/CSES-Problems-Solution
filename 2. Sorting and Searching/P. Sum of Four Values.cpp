#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, x;
  cin >> n >> x;
  int ar[n + 1];
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
  }

  unordered_map <int, vector<pair<int, int>>> mp;
  mp.reserve(n * n);

  for(int i = 1; i < n; i++) {
    for(int j = i + 1; j <= n; j++) {
      int sum = ar[i] + ar[j];
      if(sum >= x) continue;
      if(mp.find(x - sum) != mp.end()) {
        for(pair<int, int> p : mp[x - sum]) {
          if(i == p.first || i == p.second || j == p.first || j == p.second) continue;

          cout << i << ' ' << j << ' ' << p.first << ' ' << p.second << endl;
          return 0;
        }
      }
      else mp[sum].push_back({i, j});
    }
  }

  cout << "IMPOSSIBLE" << endl;

  return 0;
}
