#include <iostream>
using namespace std;

int razlikaParnihiNeparnih(int a[], int duzina){
    int sumaparnih(0), sumaneparnih(0);
    for(int i = 0; i<duzina; i++){
        if(a[i]%2==0) sumaparnih+=a[i];
        else sumaneparnih+= a[i];
    }
    return sumaparnih-sumaneparnih;
}

int main(){
    int niz[5]{-3,13,8,25,14};
    cout<<razlikaParnihiNeparnih(niz, 5);
}