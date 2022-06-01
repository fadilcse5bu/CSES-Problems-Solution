#include<bits/stdc++.h>
using namespace std;
#define ll long long int

char ch[9][9];
int ck[9][9];
int ans = 0;

void way(int row) {
  if(row > 8) {
    ans++;
    return;
  }

  for(int i = 1; i <= 8; i++) {
    if(ck[row][i] == 0 and ch[row][i] != '*') {
      for(int j = row; j <= 8; j++) {
        ck[j][i]++;
      }
      for(int j = row + 1, k = i - 1; j <= 8 and k >= 1; j++, k--) {
        ck[j][k]++;
      }
      for(int j = row + 1, k = i + 1; j <= 8 and k <= 8; j++, k++) {
        ck[j][k]++;
      }

      way(row + 1);

      for(int j = row; j <= 8; j++) {
        ck[j][i]--;
      }
      for(int j = row + 1, k = i - 1; j <= 8 and k >= 1; j++, k--) {
        ck[j][k]--;
      }
      for(int j = row + 1, k = i + 1; j <= 8 and k <= 8; j++, k++) {
        ck[j][k]--;
      }
    }
  }
}

int main()
{
  for(int i = 1; i <= 8; i++) {
    for(int j = 1; j <= 8; j++) {
      cin >> ch[i][j];
    }
  }
  way(1);
  cout << ans << endl;

	return 0;
}
