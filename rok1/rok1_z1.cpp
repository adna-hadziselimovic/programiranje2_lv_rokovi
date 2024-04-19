#include <iostream>
#include <vector>
using namespace std;

vector<int>f(int* poc, int* kraj, int k){
    vector<int> v;
    if (k<0) throw domain_error("broj manji od 0");
    if (k>9) throw domain_error("broj veci od 9");
    for(int *i = poc; i != kraj; i++){
        if((*i)%10 == k) v.push_back(*i);
    }
    return v;
}

int main(){
    int k;
    int n=7;
    int niz[7]{225,341,298,105,223,794,985};
    try{
        cin>>k;
        vector<int> vektor = f(niz, niz+n, k);
        for(int i = 0; i < vektor.size(); i++){
            cout<<vektor[i]<<" ";
        }
    }
    catch(domain_error greska){
        cout<<greska.what()<<endl; }
}
