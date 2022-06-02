#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  int n, m;
  cin >> n >> m;
  multiset <int, greater<int>> se;

  for(int i = 0; i < n; i++) {
    int h;
    cin >> h;
    se.insert(h);
  }

  while(m--) {
    int t;
    cin >> t;
    auto I = se.lower_bound(t);
    if(I == se.end()) cout << -1 << endl;
    else {
      cout << *I << endl;
      se.erase(I);
    }
  }

	return 0;
}
