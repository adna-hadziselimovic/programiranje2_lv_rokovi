#include <iostream>
using namespace std;

template<typename Tip>
bool niz(Tip p, Tip q){
    bool rastuci=true;
    bool opadajuci=true
    for(int* pok=p; pok!=q-1; pok++){
        if(*pok<*(pok+1)) opadajuci=false;
    }
    for(int* pok=p; pok!=q-1; pok++){
        if(*pok>*(pok+1)) rastuci=false;
    }
    if(rastuci && !opadajuci) return true;
    else if(!rastuci && opadajuci) return false;
    else throw int(-1);
}


int main(){
try{

}
catch(int greska){
    cout<<greska;
}
}
