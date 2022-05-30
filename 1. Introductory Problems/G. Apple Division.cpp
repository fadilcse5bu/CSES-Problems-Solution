#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector <string> vs;
ll ar[28], n, ts = 0, df = 1e18, d;

void ans(int in, ll sum) {
  if(in > n) return;
  ans(in + 1, sum + ar[in]);
  ans(in + 1, sum);

  d = ts - sum;
  df = min(abs(d - sum), df);
}

int main()
{
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
    ts += ar[i];
  }
  ans(1, 0);
  cout << df << endl;

	return 0;
}
