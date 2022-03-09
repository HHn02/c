#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#include <deque>
#include <set>
#include <vector>
#include <array>
#include <cstdio>
#include <ctype.h>
using namespace std;
int main()
{
    int t;
    (cin >> t).get();
    while(t--){
        string s;
        char c;
        getline(cin,s);
        cin >> c;
        set<char> ss;
        for(char ch : s)
            ss.insert(ch);
        if(!ss.count(c)){
            cout << "no" << endl;
            continue;
        }
        int len = s.length();
        bool res = false;
        for(int i=0;i<len;++i){
            if(s[i]==c&&i%2==0&&(len-i-1)%2==0){
                res = true;
                break;
            }
        }
        if(res) cout << "yes" << endl;
        else    cout << "no"  << endl;
    }
    return 0;
}