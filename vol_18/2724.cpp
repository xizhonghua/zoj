//3411740	2013-08-23 11:50:49	 Accepted	2724	C++	1250	1392	xxfflower
#include <iostream>
#include <queue>
#include <string>
using namespace std;

class MSG {
public:
	static int ID;
	string name;
	int par;
	int priority;
	int time_stamp;
	MSG(){}
	MSG(const MSG& msg){
		this->name = msg.name;
		this->par = msg.par;
		this->priority = msg.priority;
		this->time_stamp = msg.time_stamp;
	}
	MSG(const string& name, int par, int priority){
		this->name = name;
		this->par = par;
		this->priority = priority;
		this->time_stamp = ++(MSG::ID);
	}
	bool operator < (const MSG& msg) const {
		if(this->priority == msg.priority) { return this->time_stamp > msg.time_stamp; }
		return this->priority < msg.priority;
	}
	friend ostream& operator << (ostream& out, const MSG& msg){
		return out<<msg.name<<" "<<msg.par;
	}
};

struct MSG_Order
{
    bool operator() (const MSG* msg1, const MSG* msg2)  {
		if(msg1->priority == msg2->priority)
			return msg1->time_stamp > msg2->time_stamp;
		return msg1->priority > msg2->priority;
    }
};

int MSG::ID = 0;

int main(){

	string cmd, name;
	int par, priority;
	priority_queue<MSG*, vector<MSG*>, MSG_Order> q;
	while(cin>>cmd){
		if(cmd == "GET") {
			if(q.empty()) {
				cout<<"EMPTY QUEUE!"<<endl;
			}
			else {
				MSG* msg = q.top(); q.pop();
				cout<<*msg<<endl;
				delete msg;
			}
		}else if(cmd == "PUT"){
			cin>>name>>par>>priority;
			MSG* msg = new MSG(name, par, priority);
			q.push(msg);
		}
	}
	return 0;
}
