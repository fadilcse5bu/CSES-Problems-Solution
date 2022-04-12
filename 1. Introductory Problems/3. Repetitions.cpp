#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  string st;
  cin >> st;

  ll ans = 1, ct = 1;
  for(int i = 1; i < st.size(); i++) {
    if(st[i] == st[i - 1]) ++ct;
    else {
      ans = max(ans, ct);
      ct = 1;
    }
  }

  ans = max(ans, ct);
  cout << ans << endl;

  return 0;
}
