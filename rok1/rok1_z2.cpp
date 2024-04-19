#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>
using namespace std;

void razmak(vector<string>&v){
    for(int i = 0; i < v.size(); i++){
        string s = v[i];
        int j=0;
        while(!isalnum(s[j])) j++;
        v[i].erase(0,j);
    }
}

int main(){
vector<string> v{"   abc", "dd   e f", "    b    a    "};
razmak(v);
    for(int i = 0; i < v.size(); i++) {
        cout<<v[i]<<endl;
    }
}



