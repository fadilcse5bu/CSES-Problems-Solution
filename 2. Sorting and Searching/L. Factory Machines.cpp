#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, t;
  scanf("%d %d", &n, &t);
  int ar[n + 1];
  vector <pair<int, int>> vp;
  for(int i = 1; i <= n; i++) {
    scanf("%d", &ar[i]);
  }
  sort(vp.begin(), vp.end());

  long long int low = 1, high = 1e18, ans;
  while(low <= high) {
    long long int mid = (low + high) / 2, sum = 0;
    for(int i = 1; i <= n; i++) {
      sum += (mid / ar[i]);
      if(sum >= t) break;
    }
    if(sum >= t) {
      ans = mid;
      high = mid - 1;
    }
    else low = mid + 1;
  }

  cout << ans << endl;

  return 0;
}

/*
4 8
2 7 5 1
*/
