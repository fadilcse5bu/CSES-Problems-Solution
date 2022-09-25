#include<bits/stdc++.h>
using namespace std;
#define ll long long int

char ch[1005][1005];
int dir[1005][1005], n, m, in, in2;

int main()
{
  cin >> n >> m;
  queue <pair<int, int>> q;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      cin >> ch[i][j];
      if(ch[i][j] == 'A') {
        q.push({i, j});
        ch[i][j] = '#';
      }
      if(ch[i][j] == 'B') {
        ch[i][j] = '.';
        in = i;
        in2 = j;
      }
    }
  }

  while(!q.empty()) {
    int i = q.front().first, j = q.front().second;
    q.pop();
    if(ch[i][j + 1] == '.') {
      dir[i][j + 1] = 1;
      ch[i][j + 1] = '#';
      if(in == i and in2 == j + 1) break;
      q.push({i, j + 1});
    }
    if(ch[i + 1][j] == '.') {
      dir[i + 1][j] = 2;
      ch[i + 1][j] = '#';
      if(in == i + 1 and in2 == j) break;
      q.push({i + 1, j});
    }
    if(ch[i][j - 1] == '.') {
      dir[i][j - 1] = 3;
      ch[i][j - 1] = '#';
      if(in == i and in2 == j - 1) break;
      q.push({i, j - 1});
    }
    if(ch[i - 1][j] == '.') {
      dir[i - 1][j] = 4;
      ch[i - 1][j] = '#';
      if(in == i - 1 and in2 == j) break;
      q.push({i - 1, j});
    }
  }

  string st;
  while(dir[in][in2] > 0) {
    int v = dir[in][in2];
    if(v == 1) {
      st.push_back('R');
      --in2;
    }
    if(v == 2) {
      st.push_back('D');
      --in;
    }
    if(v == 3) {
      st.push_back('L');
      ++in2;
    }
    if(v == 4) {
      st.push_back('U');
      ++in;
    }
  }
  reverse(st.begin(), st.end());

  if(st.size() == 0) cout << "NO" << endl;
  else cout << "YES" << endl << st.size() << endl << st;

  return 0;
}
