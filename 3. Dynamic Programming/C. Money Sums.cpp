#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int dp[102][100005], ar[101], n;
void Set() {
  for(int i = 0; i < 102; i++) {
    for(int j = 0; j < 100005; j++) {
      dp[i][j] = -1;
    }
  }
}

vector <int> ve;
map <int, int> mp;

void make_sum(int i, int x) {
  if(i == n) {
    if(mp[x] == 0) {
      ve.push_back(x);
      mp[x] = 1;
    }
    return;
  }
  if(dp[i][x] == 1) return;
  make_sum(i + 1, x + ar[i]);
  make_sum(i + 1, x);
  dp[i][x] = 1;
}

int main()
{
  Set();
  cin >> n;
  for(int i = 0; i < n; i++) cin >> ar[i];
  mp[0] = 1;

  make_sum(0, 0);

  sort(ve.begin(), ve.end());
  cout << ve.size() << endl;
  for(int i = 0; i < ve.size(); i++) cout << ve[i] << ' ';

  return 0;
}
