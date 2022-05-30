#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector <string> vs;
int ar[28], n;

void ans(int in, string s, int arr[]) {
  for(int i = 0; i < 26; i++) {
    if(arr[i] > 0) {
      char ch = i + 'a';
      s.push_back(ch);
      if(in == n) vs.push_back(s);
      else {
        --arr[i];
        ans(in + 1, s, arr);
        s.pop_back();
        ++ar[i];
      }
    }
  }
}

int main()
{
  string st, s;
  cin >> st;
  n = st.size();
  for(int i = 0; i < st.size(); i++) {
    int a = st[i] - 'a';
    ar[a]++;
  }
  ans(1, s, ar);

  cout << vs.size() << endl;
  for(int i = 0; i < vs.size(); i++) cout << vs[i] << endl;

	return 0;
}
