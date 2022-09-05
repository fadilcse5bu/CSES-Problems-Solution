#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  int n, m;
  cin >> n >> m;
  int ar[n + 1], pos[n + 2];
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
    pos[ar[i]] = i;
  }
  pos[0] = 0;
  pos[n + 1] = n + 1;

  int ans = 1;
  for(int i = 1; i <= n; i++) {
    if(pos[i] < pos[i - 1]) ++ans;
  }

  while(m--) {
    int a, b;
    cin >> a >> b;
    int va = ar[a], vb = ar[b];
    if(vb < va) {
      swap(va, vb);
      swap(a, b);
    }
    if(va == vb) {
      cout << ans << endl;
      continue;
    }

    if(vb - va > 1) {
      if(pos[ar[b]] < pos[ar[a] - 1] && pos[ar[a]] > pos[ar[a] - 1]) {
        ++ans;
      }
      else if(pos[ar[b]] > pos[ar[a] - 1] && pos[ar[a]] < pos[ar[a] - 1]) {
        --ans;
      }
      if(pos[ar[b]] < pos[ar[a] + 1] && pos[ar[a]] > pos[ar[a] + 1]) {
        --ans;
      }
      else if(pos[ar[b]] > pos[ar[a] + 1] && pos[ar[a]] < pos[ar[a] + 1]) {
        ++ans;
      }

      if(pos[ar[a]] < pos[ar[b] - 1] && pos[ar[b]] > pos[ar[b] - 1]) {
        ++ans;
      }
      else if(pos[ar[a]] > pos[ar[b] - 1] && pos[ar[b]] < pos[ar[b] - 1]) {
        --ans;
      }
      if(pos[ar[a]] < pos[ar[b] + 1] && pos[ar[b]] > pos[ar[b] + 1]) {
        --ans;
      }
      else if(pos[ar[a]] > pos[ar[b] + 1] && pos[ar[b]] < pos[ar[b] + 1]) {
        ++ans;
      }

      cout << ans << endl;
    }
    else {
      if(pos[ar[b]] < pos[ar[a] - 1] && pos[ar[a]] > pos[ar[a] - 1]) {
        ++ans;
      }
      else if(pos[ar[b]] > pos[ar[a] - 1] && pos[ar[a]] < pos[ar[a] - 1]) {
        --ans;
      }

      if(pos[ar[a]] < pos[ar[b] + 1] && pos[ar[b]] > pos[ar[b] + 1]) {
        --ans;
      }
      else if(pos[ar[a]] > pos[ar[b] + 1] && pos[ar[b]] < pos[ar[b] + 1]) {
        ++ans;
      }

      if(pos[ar[a]] > pos[ar[b]]) --ans;
      else ++ans;

      cout << ans << endl;
    }

    pos[ar[a]] = b;
    pos[ar[b]] = a;
    swap(ar[a], ar[b]);
  }

  return 0;
}
