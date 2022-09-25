#include <bits/stdc++.h>
using namespace std;

int list_array[200005], n, group, tree[700005], ans = 0, val = 0;

void build_tree(int node, int i, int j, int b, int e) {
  if(b > j or e < i) return;
  if(b == e) {
    tree[node] = 1;
    return;
  }

  int mid = (b + e) / 2;
  build_tree(node * 2, i, j, b, mid);
  build_tree(node * 2 + 1, i, j, mid + 1, e);

  tree[node] = (tree[node * 2] + tree[node * 2 + 1]);
}

void query(int node, int i, int j, int b, int e, int in) {
  if(b > j or e < i) return;
  if(b == e) {
    ans = list_array[b];
    tree[node] = 0;
    return;
  }

  int mid = (b + e) / 2;
  if(tree[node * 2] < in) {
    in -= tree[node * 2];
    query(node * 2 + 1, i, j, mid + 1, e, in);
  }
  else query(node * 2, i, j, b, mid, in);

  tree[node] = (tree[node * 2] + tree[node * 2 + 1]);
}

int main()
{
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> list_array[i];

  build_tree(1, 1, n, 1, n);

  for(int i = 1; i <= n; i++) {
    int in;
    cin >> in;
    query(1, 1, n, 1, n, in);
    cout << ans << ' ';
  }


  return 0;
}
