#include <bits/stdc++.h>
using namespace std;

int free_room[200005], hotel, group, tree[700005], ans = 0, val = 0;

void build_tree(int node, int i, int j, int b, int e) {
  if(b > j or e < i) return;
  if(b == e) {
    tree[node] = free_room[b];
    return;
  }

  int mid = (b + e) / 2;
  build_tree(node * 2, i, j, b, mid);
  build_tree(node * 2 + 1, i, j, mid + 1, e);

  tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

void query_and_build(int node, int i, int j, int b, int e, int p) {
  if(b > j or e < i) return;
  if(tree[node] < p) return;
  if(b == e) {
    ans = b;
    tree[node] -= p;
    return;
  }

  int mid = (b + e) / 2;
  if(tree[node * 2] >= p) query_and_build(node * 2, i, j, b, mid, p);
  else query_and_build(node * 2 + 1, i, j, mid + 1, e, p);

  tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

int main()
{
  cin >> hotel >> group;
  for(int i = 1; i <= hotel; i++) cin >> free_room[i];

  build_tree(1, 1, hotel, 1, hotel);

  for(int i = 1; i <= group; i++) {
    int p;
    cin >> p;
    ans = 0;
    query_and_build(1, 1, hotel, 1, hotel, p);
    cout << ans << ' ';
  }

  return 0;
}
