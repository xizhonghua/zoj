// 3829418 2014-11-27 02:13:26 Accepted    3809    C++ 0   272 xxfflower
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> h(n);
        for(int i=0;i<n;i++)
            cin>>h[i];
        int c=0;
        for(int i=1;i<n-1;i++)
            if(h[i] > h[i-1] && h[i] > h[i+1]) c++;
        cout<<c<<endl;
    }  
    return 0;
}