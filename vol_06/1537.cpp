// 3834368 2014-12-03 05:30:20 Accepted    1537    C++0x   0   272 xxfflower
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

void calc(int n) {
    for(int i=1;i<=9;i++)
    {
        int sum = 0;
        for(int k=1;k<=n;k++)
        {
            sum = (sum*10 + i) % n;
            if(!sum) {
                cout<<i<<" "<<k<<endl;
                return;
            }
        }
    }

    cout<<-1<<endl;
}

int main(int argc, char** argv) {
    int n;
    while(cin>>n) 
        calc(n);
    return 0;
}