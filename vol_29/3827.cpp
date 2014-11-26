// 3829420  2014-11-27 02:28:40 Accepted    3827    C++ 0   272 xxfflower
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        double p, b;
        string unit;
        double entropy = 0.0;
        cin>>n>>unit;
        if(unit == "bit") b = 2;
        if(unit == "nat") b = exp(1.0);
        if(unit == "dit") b = 10.0;
        for(int i=0;i<n;i++)
        {
            cin>>p;

            p/=100.0;

            if(p != 0) {
                entropy += p*log(p)/log(b);
            }
        }

        cout<<std::fixed<<std::setprecision(12)<<-entropy<<endl;
    }
    return 0;
}