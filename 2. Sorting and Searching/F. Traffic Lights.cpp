#include<bits/stdc++.h>
using namespace std;
#define ll long long int

map <int, int> pre, nxt;

int main()
{
  int x, n;
  cin >> x >> n;

  vector <int> ve, ve1;
  ve.push_back(0);
  ve.push_back(x);
  for(int i = 0; i < n; i++) {
    int k;
    cin >> k;
    ve.push_back(k);
    ve1.push_back(k);
  }

  sort(ve.begin(), ve.end());
  int ans = ve[ve.size() - 1] - ve[ve.size() - 2];
  for(int i = 1; i < ve.size() - 1; i++) {
    pre[ve[i]] = ve[i - 1];
    nxt[ve[i]] = ve[i + 1];
    ans = max(ans, ve[i] - ve[i - 1]);
  }

  vector <int> fans;
  fans.push_back(ans);
  for(int i = ve1.size() - 1; i > 0; i--) {
    int df = nxt[ve1[i]] - pre[ve1[i]];
    ans = max(ans, df);
    fans.push_back(ans);
    nxt[pre[ve1[i]]] = nxt[ve1[i]];
    pre[nxt[ve1[i]]] = pre[ve1[i]];
  }

  for(int i = fans.size() - 1; i >= 0; i--) cout << fans[i] << ' ';

  return 0;
}
