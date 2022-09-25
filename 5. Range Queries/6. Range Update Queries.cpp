#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll n, q, ar[200005], prop[2000005];
ll ans = 0;

void propagate(int node, int i, int j, int b, int e, ll v) {
  if(b > j or e < i) return;
  if(b >= i and e <= j) {
    prop[node] += v;
    return;
  }

  int mid = (b + e) / 2;
  propagate(node * 2, i, j, b, mid, v);
  propagate(node * 2 + 1, i, j, mid + 1, e, v);
}

void queryTree(int node, int i, int j, int b, int e) {
  if(b > j or e < i) return;
  ans += prop[node];
  if(b >= i and e <= j) return;

  int mid = (b + e) / 2;
  queryTree(node * 2, i, j, b, mid);
  queryTree(node * 2 + 1, i, j, mid + 1, e);
}

int main()
{
  cin >> n >> q;
  for(int i = 1; i <= n; i++) cin >> ar[i];

  while(q--) {
    ll typ, a, b, u;
    cin >> typ;
    if(typ == 1) {
      cin >> a >> b >> u;
      propagate(1, a, b, 1, n, u);
    }
    else {
      cin >> a;
      ans = 0;
      queryTree(1, a, a, 1, n);
      ans += ar[a];
      cout << ans << endl;
    }
  }

  return 0;
}
