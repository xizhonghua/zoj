// 3829483   2014-11-27 12:46:27 Accepted    3798    C++0x   110 272 xxfflower 
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int compute_min_score(int n) {
    if (((n+1)>>1) & 0x01) return 1;
    return 0;
}

void solve(int n) {
    int min_score = compute_min_score(n);
    int max_score = n - compute_min_score(n-1);
    cout<<min_score<<" "<<max_score<<endl;
    for(int i=n;i>1;i--)
        cout<<i<<" ";
    cout<<1<<endl;
    for(int i=n-1;i>0;i--)
        cout<<i<<" ";
    cout<<n<<endl;
}

int main(int argc, char** argv) {

    int n;
    while(cin>>n)
        solve(n);

    return 0;
}