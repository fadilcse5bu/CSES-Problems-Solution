#include<bits/stdc++.h>
using namespace std;

int ar[200005], n, q, tree[2000005], ans = INT_MAX;

void buildTree(int node, int b, int e) {
  if(b == e) {
    tree[node] = ar[b];
    return;
  }

  int mid = (b + e) / 2;
  buildTree(node * 2, b, mid);
  buildTree(node * 2 + 1, mid + 1, e);

  tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

void query(int node, int i, int j, int b, int e) {
  if(b > j or e < i) return;
  if(b >= i and e <= j) {
    ans = min(ans, tree[node]);
    return;
  }

  int mid = (b + e) / 2;
  query(node * 2, i, j, b, mid);
  query(node * 2 + 1, i, j, mid + 1, e);
}

int main()
{
  cin >> n >> q;
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
  }

  buildTree(1, 1, n);

  while(q--) {
    int a, b;
    cin >> a >> b;
    ans = INT_MAX;
    query(1, a, b, 1, n);
    cout << ans << endl;
  }

  return 0;
}
