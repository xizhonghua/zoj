//3829414   2014-11-27 02:07:29 Accepted    3819    C++ 10  272 xxfflower
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--)
    {
        int n1, n2, s;

        cin>>n1>>n2;

        double s1 = 0.0, s2 = 0.0; 

        for(int i=0;i<n1-1;i++) { cin>>s; s1 += s; }
        for(int i=0;i<n2;i++) { cin>>s; s2 += s; }

        double l = ceil(s2 / n2);
        double u = floor(s1 / (n1-1));

        if(l * n2 <= s2) l++;
        if(u * (n1-1) >= s1) u--;

        cout<<(int)l<<" "<<(int)u<<endl;

    }
    return 0;
}