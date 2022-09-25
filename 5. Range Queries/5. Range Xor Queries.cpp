#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int n, q, ar[200005], tree[2000005];

void buildTree(int node, int b, int e) {
  if(b == e) {
    tree[node] = ar[b];
    return;
  }

  int mid = (b + e) / 2;
  buildTree(node * 2, b, mid);
  buildTree(node * 2 + 1, mid + 1, e);

  tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}

int queryTree(int node, int i, int j, int b, int e) {
  if(b > j or e < i) return 0;
  if(b >= i and e <= j) return tree[node];

  int mid = (b + e) / 2;
  int v1 = queryTree(node * 2, i, j, b, mid);
  int v2 = queryTree(node * 2 + 1, i, j, mid + 1, e);

  return v1 ^ v2;
}

int main()
{
  cin >> n >> q;
  for(int i = 1; i <= n; i++) cin >> ar[i];
  buildTree(1, 1, n);

  while(q--) {
    int a, b;
    cin >> a >> b;
    cout << queryTree(1, a, b, 1, n) << endl;
  }

  return 0;
}
