// 3829422  2014-11-27 03:13:03 Accepted    3804    C++0x   540 272 xxfflower
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
using namespace std;

int awake_count(int x, int y, const vector<string>& b)
{
    int c = 0;
    if (b[y-1][x-1] == '1') c++;
    if (b[y-1][x] == '1') c++;
    if (b[y-1][x+1] == '1') c++;

    if (b[y][x-1] == '1') c++;
    if (b[y][x+1] == '1') c++;
    
    if (b[y+1][x-1] == '1') c++;
    if (b[y+1][x] == '1') c++;
    if (b[y+1][x+1] == '1') c++;
    
    
    
    return c;
}

void print_status(const vector<string>& b, bool debug = false)
{
    if(debug) cout<<endl<<string(40,'-')<<endl;
    for(int i=1;i<b.size()-1;i++)
        cout<<b[i].substr(1, b[i].length()-2)<<endl;
    if(debug) cout<<string(40,'-')<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,f,k;
        string line;
        vector<string> b;
        map<int, vector<pair<int,int> > > l;

        cin>>n>>m>>f>>k;
        std::getline (std::cin, line);

        b.push_back(string(m+2, 'X'));

        for(int i=0;i<n;i++) {
            std::getline (std::cin, line);
            b.push_back("X" + line + "X");
        }

        b.push_back(string(m+2, 'X'));

        for(int i=0;i<k;i++)
        {
            int ti, xi, yi;
            cin>>ti>>xi>>yi;
            l[ti].push_back(make_pair(xi, yi));
        }

        for(int tt=1;tt<=f;tt++)
        {
            auto lb = b;
            for(int y=1;y<=n;y++)
                for(int x=1;x<=m;x++)
                {
                    int ac = awake_count(x, y, lb);
                    int a = b[y][x];
                    if(a == '1') {
                        if(ac < 2 || ac > 3) b[y][x] = '0';
                    }
                    else if (a == '0') {
                        if(ac == 3) b[y][x] = '1';
                    }
                }

            // handle leave message
            for(auto m : l[tt])
            {
                int y = m.first;
                int x = m.second;
                b[y][x] = 'X'; // leave
            }
        }

        print_status(b);

    }
    return 0;
}