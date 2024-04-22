#include <iostream>
using namespace std;

double* f(double niz[], int n, int k){
    if(k<=0) throw domain_error("k je manje ili jednako 0");
    int vel = n-k+1;
    double* niz1 = new double[vel];
    for(int i = 0; i<vel; i++){
        int brojac(0);
        double suma(0);
        while (brojac != k) {
            suma+=niz[i+brojac];
            brojac++;
        }
        niz1[i]=suma;
    }
    return niz1;
}

int main(){
    double niz[6]{2,1,4,5,8,1};
    try{
        cout<<*f(niz,6,3);
    }
    catch(domain_error greska){
        cout<<greska.what()<<endl;
    }
}