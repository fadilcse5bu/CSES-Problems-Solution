#include <bits/stdc++.h>
using namespace std;

long long int number_of_list, content[5005], pre_sum[5005];
long long int dp[5005][5005];

long long int find_maximum_score(int l, int r) {
  if(l == r) return dp[l][r] = content[l];
  if(dp[l][r] != -1) return dp[l][r];

  long long int v1 = content[l] + (pre_sum[r] - pre_sum[l]) - find_maximum_score(l + 1, r);
  long long int v2 = content[r] + (pre_sum[r - 1] - pre_sum[l - 1]) - find_maximum_score(l, r - 1);

  return dp[l][r] = max(v1, v2);
}

int main()
{
  cin >> number_of_list;
  for(int i = 1; i <= number_of_list; i++) {
    cin >> content[i];
    pre_sum[i] = pre_sum[i - 1] + content[i];
  }

  for(int i = 0; i <= number_of_list; i++) {
    for(int j = 0; j <= number_of_list; j++) {
      dp[i][j] = -1;
    }
  }

  cout << find_maximum_score(1, number_of_list);

  return 0;
}
