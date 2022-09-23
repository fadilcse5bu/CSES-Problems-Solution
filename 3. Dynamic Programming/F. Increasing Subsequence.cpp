#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define dd double

int main()
{
  int n, a;
  cin >> n >> a;
  vector <int> tail;
  tail.push_back(a);

  for(int i = 1; i < n; i++) {
    cin >> a;
    if(a > tail[tail.size() - 1]) tail.push_back(a);
    else {
      auto indx = upper_bound(tail.begin(), tail.end(), a) - tail.begin();
      if(indx != 0 and tail[indx - 1] == a) --indx;
      tail[indx] = a;
    }
  }

  cout << tail.size() << endl;

  return 0;
}
