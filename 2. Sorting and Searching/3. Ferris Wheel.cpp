#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  ll n, x;
  cin >> n >> x;
  ll p[n], ans = 0;
  for(int i = 0; i < n; i++) cin >> p[i];
  sort(p, p + n);
  priority_queue <ll> pq;
  for(int i = n - 1; i >= 0; i--) {
    if(pq.empty()) {
      ++ans;
      pq.push(x - p[i]);
    }
    else if(p[i] <= pq.top()) pq.pop();
    else {
      ++ans;
      pq.push(x - p[i]);
    }
  }

  cout << ans << endl;

	return 0;
}
