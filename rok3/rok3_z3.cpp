#include <iostream>
#include <cmath>
using namespace std;

int faktorijel(int n){
    if(n==1) return n;
    else return n*(faktorijel(n-1));
}

double Kosinus(double x, int n){
    double cosx(0);
    cosx+=((pow(-1,n))/(faktorijel(2*n)))*pow((double)x,2*n);
    return cosx;
}

int main(){
    double eps = 0.001;
    double x;
    int n(1);
    cin>>x;
    while(Kosinus(x,n)-cos(x)>eps){
        n++;
        cout<<Kosinus(x,n)<<cos(x)<<endl;
    }
    cout<<n;
}
