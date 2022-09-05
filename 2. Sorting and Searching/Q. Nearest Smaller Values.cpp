#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;

  stack <pair<int, int>> sp;
  sp.push({0, 0});

  for(int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    while(sp.top().first >= a) sp.pop();
    cout << sp.top().second << ' ';
    sp.push({a, i});
  }


  return 0;
}
