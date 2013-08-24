//3412504	2013-08-24 08:19:35	 Accepted	3185	C++	0	188	xxfflower
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

int main(){
	string line;
	while(std::getline(cin, line) && line.find(".") == string::npos){
		bool append = true;
		size_t pos = line.find(" ++ ");
		if(pos == std::string::npos){
			pos = line.find(" -- ");
			append = false;
		}
		string ls1 = line.substr(1, pos-2);
		string ls2 = line.substr(pos+5, line.length()-pos-6);

		vector<string> l1 = split(ls1, ',');
		vector<string> l2 = split(ls2, ',');

		if(append){
			l1.insert(l1.end(), l2.begin(), l2.end());
		}else{
			for(size_t i=0;i<l2.size();i++)
			{
				for(size_t j=0;j<l1.size();j++)
					if(l1[j] == l2[i]) { l1.erase(l1.begin()+j); break;}
			}
		}

		cout<<"[";
		for(vector<string>::const_iterator it = l1.begin(); it != l1.end(); ++it){
			if(it!=l1.begin()) cout<<",";
			cout<<*it;
		}
		cout<<"]"<<endl;
	}
	return 0;
}
