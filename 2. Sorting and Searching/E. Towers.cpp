#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  int n;
  cin >> n;
  multiset <int> ms;

  for(int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    auto I = ms.upper_bound(a);
    ms.insert(a);
    if(I != ms.end()) {
      int v = *I;
      ms.erase(I);
    }
  }
  cout << ms.size() << endl;

  return 0;
}
