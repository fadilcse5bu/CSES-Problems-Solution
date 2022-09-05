#include <bits/stdc++.h>
using namespace std;



int main()
{
  int n, x;
  scanf("%d %d", &n, &x);
  int ar[n + 1];
  vector <pair<int, int>> vp;
  for(int i = 1; i <= n; i++) {
    scanf("%d", &ar[i]);
    vp.push_back({ar[i], i});
  }
  sort(vp.begin(), vp.end());

  for(int i = 1; i <= n; i++) {
    int low = 0, high = n - 1;
    while(low < high) {
      if(vp[low].second == i) low++;
      else if(vp[high].second == i) high--;
      else if(vp[low].first + vp[high].first + ar[i] > x) high--;
      else if(vp[low].first + vp[high].first + ar[i] < x) low++;
      else {
        cout << i << ' ' << vp[low].second << ' ' << vp[high].second << endl;
        return 0;
      }
    }
  }

  printf("IMPOSSIBLE\n");

  return 0;
}

/*
4 8
2 7 5 1
*/
