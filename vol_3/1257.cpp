// 3831054 2014-11-29 04:19:26 Accepted    1257    C++0x   0   272 xxfflower
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <climits>
using namespace std;

const int MAX_LOTS = 20;

struct car {
    int org;
    int cur;
    int parked;

    int dist_to(const int target_pos) {
        if(this->parked>0) return INT_MAX;
        int dist = target_pos - this->cur;
        if(dist<0) dist+=MAX_LOTS;
        return dist;
    }

    void move(const int dist) {
        if(this->parked>0) return;
        this->cur += dist;
        if(this->cur > MAX_LOTS)
            this->cur -= MAX_LOTS;
    }
};

int main(int argc, char** argv) {
    vector<car> cars;
    int p;

    while(cin>>p && p!=99)
        cars.push_back((car){p,p,-1});

    while(cin>>p) {
        int best_dist = MAX_LOTS+1;
        car* best_car = NULL;

        for(auto& c : cars) {
            int dist = c.dist_to(p);
            if(dist < best_dist) {
                best_dist = dist;
                best_car = &c;
            }
        }

        if(best_car)
            best_car->parked = p;

        for(auto& c : cars)
            c.move(best_dist);
    }

    for(const auto& c : cars) {
        cout<<"Original position "<<c.org;
        if(c.parked>0) 
            cout<<" parked in "<<c.parked<<endl;
        else 
            cout<<" did not park"<<endl;
    }
    
    return 0;
}