// 3934609  2017-03-13 08:38:54 Accepted  3713  C++0x 290 6428  xxfflower
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void put_hex(int byte) {
   cout << hex << uppercase << setfill('0') << setw(2) << byte;
}

void put_str(const string& s) {
  for(char c : s)
    put_hex(c);
}

void put_len(int length) {
  while(length>=128) {
    put_hex(length % 128 + 128);
    length >>= 7;
  }
  put_hex(length);
}

int main(int argc, char const *argv[])
{
  int n;
  cin>>n;
  string s;
  getline(cin, s);

  while(n--) {
    getline(cin, s);
    put_len(s.length());
    put_str(s);
    cout<<endl;
  }
  return 0;
}