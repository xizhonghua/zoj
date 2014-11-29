// 3831199 2014-11-29 12:37:12 Accepted    1602    C++0x   0   272 xxfflower
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <climits>
using namespace std;

int main(int argc, char** argv) {
    int n;
    while(cin>>n){
        vector<int> v(n);
        vector<vector<int> > s(n, vector<int>(n));
        for(int i=0;i<n;i++)
            cin>>v[i];
        for(int c=3;c<=n;c++)
            for(int i=0;i<=n-c;i++) {
                int j=i+c-1;
                s[i][j] = INT_MAX;
                for(int k=i+1;k<j;k++)
                    s[i][j] = min(s[i][j], s[i][k] + s[k][j] + v[i]*v[k]*v[j]);
            }
        cout<<s[0][n-1]<<endl;
    }
    return 0;
}