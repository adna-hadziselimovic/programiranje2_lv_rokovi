#include <iostream>
using namespace std;

template <typename Tip>
bool fun(Tip** mat, int n) {
    if (n <= 0) throw domain_error("n manje ili jednako od 0");
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(mat[i][j]==mat[j][i]) return true;
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    int** matrica = new int* [n];
    for(int i = 0; i<n; i++)
        matrica[i] = new int[n];
    try {
        for(int i = 0; i<n; i++) {
            for (int j = 0; j < n; j++) {
                cin>>matrica[i][j];
            }
        }
        cout<<fun(matrica, n);
    }
    catch(domain_error greska){
        cout<<greska.what()<<endl;
    }
    for (int i = 0; i < n; i++)
        delete[] matrica[i];
    delete[] matrica;
}