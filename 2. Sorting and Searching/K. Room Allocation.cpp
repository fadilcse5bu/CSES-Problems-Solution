#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector <pair<pair<int, int>, int>> vp;
  int ans[n];
  for(int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    vp.push_back({{a, b}, i});
  }
  sort(vp.begin(), vp.end());

  priority_queue <pair<int, int>, vector <pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({vp[0].first.second + 1, 1});
  ans[vp[0].second] = 1;

  int ct = 1;
  for(int i = 1; i < n; i++) {
    if(pq.top().first <= vp[i].first.first) {
      int index = pq.top().second;
      pq.pop();
      pq.push({vp[i].first.second + 1, index});
      ans[vp[i].second] = index;
    }
    else {
      ++ct;
      pq.push({vp[i].first.second + 1, ct});
      ans[vp[i].second] = ct;
    }
  }

  cout << ct << endl;
  for(int i = 0; i < n; i++) cout << ans[i] << ' ';


  return 0;
}
