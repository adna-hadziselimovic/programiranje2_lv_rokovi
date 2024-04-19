#include <iostream>
#include <vector>
using namespace std;

template<typename Tip>
Tip sedlo(Tip** matrica, int n){
    int min = matrica[0][0];
    int max = matrica [0][0];
    int poz=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            if(matrica[i][j]<min) {
                min = matrica[i][j];
                poz = j;
            }
        }
        for(int k=0; k < n; k++){
            if(matrica[k][poz]>max) max = matrica[k][poz];
            else throw "izuzetak";
        }

    return max;
}

int main(){
int n;
cin>>n;
int** matrica = new int* [n];
for(int i = 0; i < n; i++) matrica[i] = new int[n];

for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
        cin>>matrica[i][j];

try{
    cout<<sedlo(matrica,  n);
}
catch(...){
    cout<< "nema sedlo"<<endl;
}
for(int i = 0; i < n; i++) delete [] matrica[i];
delete [] matrica;
}