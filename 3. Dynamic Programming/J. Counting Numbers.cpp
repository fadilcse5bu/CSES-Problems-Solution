#include <bits/stdc++.h>
using namespace std;

int main()
{
  string a, b;
  cin >> a >> b;
  int len = b.size();
  long long int dpb[len+1], ansb = 0;
  dpb[len] = 1;
  for(int i = len - 1; i >= 0; i--)
    dpb[i] = dpb[i+1] * 9;

  for(int i = 0; i < len; i++) {
    ansb += dpb[i+1];
  }
  int pre = 0;
  for(int i = 0; i < len; i++) {
    int dig = b[i] - '0';
    if(pre < dig) --dig;
    ansb += (dig*dpb[i+1]);
    dig = b[i] - '0';
    if(pre == dig) break;
    pre = dig;
  }
  int ck = 0;
  for(int i = 1; i < len; i++) {
    if(b[i] == b[i-1]) {
      ck = 1;
      break;
    }
  }
  if(ck == 0) ++ansb;
  if(b == "0") --ansb;

  len = a.size();
  long long int dpa[len+1], ansa = 0;
  dpa[len] = 1;
  for(int i = len - 1; i >= 0; i--)
    dpa[i] = dpa[i+1] * 9;

  for(int i = 0; i < len; i++) {
    ansa += dpa[i+1];
  }
  pre = 0;
  for(int i = 0; i < len; i++) {
    int dig = a[i] - '0';
    if(pre < dig) --dig;
    ansa += (dig*dpa[i+1]);
    dig = a[i] - '0';
    if(pre == dig) break;
    pre = dig;
  }
  if(a == "0") --ansa;

  cout << ansb - ansa << endl;
}
