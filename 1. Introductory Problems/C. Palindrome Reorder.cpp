#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  string st;
  cin >> st;

  int ct[300] = {0}, ctt = 0;
  char ch;
  for(int i = 0; i < st.size(); i++) {
    ++ct[st[i]];
    if(ct[st[i]] % 2 == 1) ++ctt;
    else --ctt;
  }

  if(ctt > 1) {
    cout << "NO SOLUTION" << endl;
    return 0;
  }

  for(int i = 'A'; i <= 'Z'; i++) {
    if(ct[i] % 2 == 0) {
      for(int j = 1; j <= ct[i] / 2; j++) {
        char ch = i;
        cout << ch;
      }
    }
  }
  for(int i = 'A'; i <= 'Z'; i++) {
    if(ct[i] % 2 == 1) {
      for(int j = 1; j <= ct[i]; j++) {
        char ch = i;
        cout << ch;
      }
    }
  }
  for(int i = 'Z'; i >= 'A'; i--) {
    if(ct[i] % 2 == 0) {
      for(int j = 1; j <= ct[i] / 2; j++) {
        char ch = i;
        cout << ch;
      }
    }
  }

	return 0;
}
