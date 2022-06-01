#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll ans = 0, ct = 0;
string st;
int path[9][9];

void totalWay(int r, int c, int in) {
  if(r == 7 and c == 1) {
    if(in == st.size()) ++ans;
    return;
  }

  if((path[r][c - 1] and path[r][c + 1]) and (!path[r - 1][c] and !path[r + 1][c])) return;
  if((path[r - 1][c] and path[r + 1][c]) and (!path[r][c - 1] and !path[r][c + 1])) return;

  path[r][c] = 1;

  if(st[in] == 'U') {
    if(path[r - 1][c] == 0) totalWay(r - 1, c, in + 1);
  }
  else if(st[in] == 'D') {
    if(path[r + 1][c] == 0) totalWay(r + 1, c, in + 1);
  }
  else if(st[in] == 'L') {
    if(path[r][c - 1] == 0) totalWay(r, c - 1, in + 1);
  }
  else if(st[in] == 'R') {
    if(path[r][c + 1] == 0) totalWay(r, c + 1, in + 1);
  }
  else {
    if(path[r - 1][c] == 0) totalWay(r - 1, c, in + 1);
    if(path[r + 1][c] == 0) totalWay(r + 1, c, in + 1);
    if(path[r][c - 1] == 0) totalWay(r, c - 1, in + 1);
    if(path[r][c + 1] == 0) totalWay(r, c + 1, in + 1);
  }
  path[r][c] = 0;
}

int main()
{
  cin >> st;
  for(int i = 0; i < 9; i++) {
    path[0][i] = 1;
    path[i][0] = 1;
    path[8][i] = 1;
    path[i][8] = 1;
  }
  totalWay(1, 1, 0);
  cout << ans << endl;

	return 0;
}
