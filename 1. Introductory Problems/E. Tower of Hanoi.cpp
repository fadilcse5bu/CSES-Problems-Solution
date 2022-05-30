#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector <pair<int, int>> vp;

void toh(int n, int a, int b, int c) {
  if(n == 1) vp.push_back({a, b});
  else {
    toh(n - 1, a, c, b);
    vp.push_back({a, b});
    toh(n - 1, c, b, a);
  }
}

int main()
{
  int n;
  cin >> n;
  toh(n, 1, 3, 2);

  cout << vp.size() << endl;
  for(int i = 0; i < vp.size(); i++) cout << vp[i].first << ' ' << vp[i].second << endl;

	return 0;
}
