#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll ar[200005], n, q, tree[2000005], ans = 0;

void buildTree(int node, int b, int e) {
  if(b == e) {
    tree[node] = ar[b];
    return;
  }

  int mid = (b + e) / 2;
  buildTree(node * 2, b, mid);
  buildTree(node * 2 + 1, mid + 1, e);

  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void query(int node, int i, int j, int b, int e) {
  if(b > j or e < i) return;
  if(b >= i and e <= j) {
    ans += tree[node];
    return;
  }

  int mid = (b + e) / 2;
  query(node * 2, i, j, b, mid);
  query(node * 2 + 1, i, j, mid + 1, e);
}

void updateTree(int node, int i, int j, int b, int e) {
  if(b > j or e < i) return;
  if(b >= i and e <= j) {
    tree[node] = ar[i];
    return;
  }

  int mid = (b + e) / 2;
  updateTree(node * 2, i, j, b, mid);
  updateTree(node * 2 + 1, i, j, mid + 1, e);

  tree[node] = tree[node * 2 + 1] + tree[node * 2];
}

int main()
{
  cin >> n >> q;
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
  }

  buildTree(1, 1, n);

  while(q--) {
    int a, b, tp;
    cin >> tp >> a >> b;
    ans = 0;
    if(tp == 1) {
      ar[a] = b;
      updateTree(1, a, a, 1, n);
    }
    else {
      query(1, a, b, 1, n);
      cout << ans << endl;
    }
  }

  return 0;
}
