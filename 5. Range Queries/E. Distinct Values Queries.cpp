#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int ar[200005], tree[200005];
map <int, int> last_visit;

void update_tree(int idx, int val, int n)
{
    while(idx <= n) {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

int query(int l, int r)
{
    int a = 0, b = 0;
    while(r > 0) {
        b += tree[r];
        r -= (r & -r);
    }
    while(l > 0) {
        a += tree[l];
        l -= (l & -l);
    }

    return b - a;
}

int main()
{
  int n, q;
  cin >> n >> q;
  for(int i = 1; i <= n; i++) cin >> ar[i];

  vector <pair<pair<int, int>, int>> vp;
  for(int i = 1; i <= q; i++) {
    int l, r;
    cin >> l >> r;
    vp.push_back({{r, l}, i});
  }
  sort(vp.begin(), vp.end());

  int ans[q + 1] = {0}, cnt = 0;
  for(int i = 1; i <= n; i++) {
    if(last_visit[ar[i]] > 0) {
      update_tree(last_visit[ar[i]], -1, n);
    }

    last_visit[ar[i]] = i;
    update_tree(i, 1, n);

    while(cnt < n and vp[cnt].first.first == i) {
      ans[vp[cnt].second] = query(vp[cnt].first.second - 1, vp[cnt].first.first);
      ++cnt;
    }
  }

  for(int i = 1; i <= q; i++) cout << ans[i] << endl;

  return 0;
}
