//3847612   2015-01-08 04:18:16 Accepted    3775    C++0x   0   272 xxfflower
#include <iostream>
#include <string>
using namespace std;

class Program
{
public:    
    static string run(const string& source) {
        string output;
        for(int i=0;i<source.length();i++)
            switch(source[i]) {
                case '_': output += source; break;
                case '!': output += "Hello, world!"; break;
            }
        return output;
    }
};

int main(int argc, char** argv) {
    int t;
    string source;
    cin>>t;    
    getline(cin, source);
    while(t--) {        
        getline(cin, source);
        cout<<((Program::run(source)==source)?"Yes":"No")<<endl;            
    }
    return 0;
}