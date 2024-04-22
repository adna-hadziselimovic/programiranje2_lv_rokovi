#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> najmanjiProstiDjelioci(vector<int>a){
    vector<int>djelioci;
    for(int i = 0; i<a.size();i++) {
        bool dodan = false;
        for (int j = 2; j <= sqrt(a[i]); j++) {
            if (a[i] % j == 0) {
                djelioci.push_back(j);
                dodan=true;
                break;
            }
        }
        if(!dodan) djelioci.push_back(a[i]);
    }
    return djelioci;
}

int main(){
    vector<int>v{5,8,21,125,36};
    for(int i =0;i<v.size();i++) cout<<najmanjiProstiDjelioci(v)[i]<<endl;

}