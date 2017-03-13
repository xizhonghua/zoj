// 3934633  2017-03-13 10:48:25 Accepted  3612  C++0x 900 540 xxfflower
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
typedef long long int64;

int main() {
  int t,n,x;
  char op[20];
  cin>>t;

  while(t--) {
    scanf("%d", &n);
    
    vector<int64> a;

    while(n--) {
      scanf("%s %d", op, &x);
      auto it = lower_bound(a.begin(), a.end(), x);

      if(op[0] == 'r') {
        if(it==a.end() || *it != x) {
          puts("Wrong!");
          continue;
        } else {
          a.erase(it);
          if(a.empty()) {
            puts("Empty!");
            continue;
          }
        }
      } else if(op[0] == 'a') {
        a.insert(it, x);
      }

      if(a.size()%2==1) {
        printf("%lld\n", a[a.size()/2]);
      } else {
        int64 ans = a[a.size()/2-1] + a[a.size()/2];
        if(ans%2==0) 
          printf("%lld\n", ans/2);
        else 
          printf("%.1lf\n", ans/2.0);
      }
    }
  }

  return 0;
}