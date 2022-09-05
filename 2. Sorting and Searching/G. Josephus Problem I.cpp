#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector <int> ve, ve1;

  for(int i = 1; i <= n; i++) {
    ve.push_back(i);
  }

  while(n > 1) {
    for(int i = 1; i < n; i += 2) {
      cout << ve[i] << ' ';
    }
    if(n % 2 == 1) {
      ve1.push_back(ve[n - 1]);
    }
    for(int i = 0; i < n - 1; i += 2) {
      ve1.push_back(ve[i]);
    }

    ve.clear();
    ve = ve1;
    ve1.clear();
    n = ve.size();
  }

  cout << ve[0] << ' ';


  return 0;
}
