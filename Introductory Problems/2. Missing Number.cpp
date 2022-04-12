#include<bits/stdc++.h>
using namespace std;

int main()
{
  long int n, ps, sum = 0;
  cin >> n;
  ps = n * (n + 1) / 2;
  --n;
  while(n--) {
    long int a;
    cin >> a;
    sum += a;
  }
  cout << ps - sum << endl;

	return 0;
}
