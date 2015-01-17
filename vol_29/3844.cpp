//3850609 2015-01-18 01:19:49 Accepted  3844  C++0x 0 272 xxfflower
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

  int t,n;
  cin>>t;
  while(t--) {
    cin>>n;
    vector<int> num(n);
    for(int i=0;i<n;i++)
      cin>>num[i];    
    while(true)
    {
      int& max_v = *max_element(num.begin(), num.end());
      int& min_v = *min_element(num.begin(), num.end());    

      if(min_v == max_v)
      {
        cout<<min_v<<endl;
        break;
      }

      int new_v = max_v - min_v;
      max_v = new_v;
      min_v = new_v;
    }
  }

  return 0;
}