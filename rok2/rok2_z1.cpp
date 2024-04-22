#include <iostream>
#include <vector>
#include <string>
using namespace std;

void dobars(vector<string>&s, bool dobar){
    for(int i = 1; i < s.size();i++) {
        if (s[i-1].size() == s[i].size()){
            int vel  = s[i-1].size();
            int brojac(0);
            string v1 = s[i-1];
            string v2 = s[i];
            for(int i = 0; i < vel; i++){
                if (v1[i]==v2[i]) brojac++;
            }
            if(vel-1==brojac) dobar = true;
        }
        else dobar = false;
    }
    cout<<dobar;
}

int main(){
    vector<string>s1{"abc","abd","cbd","cbf"};
    vector<string>s2{"abcd","abd","cbd","cbde"};
    bool d = true;
dobars(s1,d);
dobars(s2, d);

}