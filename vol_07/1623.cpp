//3404508	2013-08-17 04:06:35	 Accepted	1623	C++	0	188	花花的表世界
#include <iostream>
#include <string>
#include <cstdio>
#include <cctype>
using namespace std;

typedef unsigned int uint32;

int main(){
	int T,L;
	cin>>T;
	while(T--){
		string s,line;
		cin>>L; std::getline(std::cin, line);
		for(int i=0;i<L;i++)
		{
			std::getline(std::cin, line);
			s += line;
			s+= "\n";
		}
		int count = 0;
		size_t pos = 0, tpos = 0;
		while(pos < s.length()){
			tpos = pos;
			size_t ms = s.find("/*", pos);
			size_t cs = s.find("//", pos);

			if(ms!=std::string::npos && ms < cs){
				size_t me = s.find("*/", ms+2);
				if(me != std::string::npos)
				{
					tpos = me;
					for(size_t i=ms;i<=me;i++)
						s[i] = toupper(s[i]);
					count++;
				}
			}

			if(ms > cs){
				if(cs!=std::string::npos){
					count++;
					size_t ce = s.find("\n", cs+2);
					for(size_t i=cs;i<=ce;i++)
						s[i] = toupper(s[i]);
					tpos = ce;
				}
			}

			pos = tpos == pos ? s.length() : tpos+1;
		}
		cout<<count<<endl;
		cout<<s<<endl;

	}
	return 0;
}
