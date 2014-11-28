// 3831048  2014-11-29 04:08:49 Accepted    1257    C++0x   0   272 xxfflower
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct car {
    int start;
    int cur;
    int parked;
};

int main(int argc, char** argv) {
    
    vector<car> cars;

    int p;
    while(true) {
        cin>>p;        
        if (p==99) break;

        car c;
        c.start = p;
        c.cur = p;
        c.parked = -1;

        cars.push_back(c);
    }

    while(cin>>p) {
        int best_dist = 21;
        car* best_car = NULL;

        for(auto& c : cars) {
            if(c.parked > 0) continue;
            int dist = p - c.cur;
            if(dist<0) dist+=20;
            if(dist < best_dist) {
                best_dist = dist;
                best_car = &c;
            }
        }

        if(best_car)
            best_car->parked = p;
        

        for(auto& c : cars) {
            if(c.parked > 0) continue;
            c.cur += best_dist;
            if(c.cur > 20) c.cur -= 20;
        }
    }

    for(const auto& c : cars) {
        cout<<"Original position "<<c.start;
        if(c.parked>0) 
            cout<<" parked in "<<c.parked<<endl;
        else 
            cout<<" did not park"<<endl;
    }
    
    return 0;
}