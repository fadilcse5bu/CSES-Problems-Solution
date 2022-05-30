#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  int n, p;
  cin >> n;
  string st;
  for(int i = 0; i < n; i++) st.push_back('0');
  p = pow(2, n);

  map <string, int> mp;
  mp[st] = 1;
  cout << st << endl;
  for(int i = 2; i <= p; i++) {
    for(int j = 0; j < n; j++) {
      string s = st;
      if(s[j] == '0') s[j] = '1';
      else s[j] = '0';
      if(mp[s] == 0) {
        mp[s] = 1;
        cout << s << endl;
        st = s;
        break;
      }
    }
  }

	return 0;
}
