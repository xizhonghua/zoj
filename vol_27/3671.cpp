//3494939	2013-12-23 09:16:57	 Accepted	3671	C++	0	272	xxfflower
/*

 * 3671.cpp
 *
 *  Created on: Dec 22, 2013
 *      Author: zhonghua
 */
#include <iostream>
#include <string>
#include <map>
#include <utility>
using namespace std;




bool sp(string s) {
	map<pair<char, char>, int > m;
	for(size_t i=0;i<s.length();i+=2) {
		char num = s[i];
		char suit = s[i+1];
		pair<char, char> p = std::make_pair(num, suit);
		if(m.count(p) > 0) {
			m[p] ++;
			if(m[p]>2) return false;
		}else {
			m[p] = 1;
		}
	}

	return (m.size() == 7);
}

bool to(string s) {
	map<pair<char, char>, int > m;
	for(size_t i=0;i<s.length();i+=2) {
		char num = s[i];
		char suit = s[i+1];
		pair<char, char> p = std::make_pair(num, suit);
		if(m.count(p) > 0) {
			m[p] ++;
		}else {
			m[p] = 1;
		}
	}

	if(m.size()!=13) return false;
	if(!m.count(std::make_pair('1','s'))) return false;
	if(!m.count(std::make_pair('9','s'))) return false;
	if(!m.count(std::make_pair('1','m'))) return false;
	if(!m.count(std::make_pair('9','m'))) return false;
	if(!m.count(std::make_pair('1','p'))) return false;
	if(!m.count(std::make_pair('9','p'))) return false;
	for(int i=1;i<=7;i++)
		if(!m.count(std::make_pair('0'+i,'z'))) return false;
	return true;
}

int main() {
	string s;
	while(cin>>s) {
		if(sp(s)) cout<<"Seven Pairs"<<endl;
		else if(to(s)) cout<<"Thirteen Orphans"<<endl;
		else cout<<"Neither!"<<endl;
	}
	return 0;
}
