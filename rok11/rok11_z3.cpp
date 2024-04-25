#include <iostream>
#include <algorithm>
#include <stdexcept>

using namespace std;

template <typename T>
void ispisi_mat(T** mat, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

template <typename T>
T** zamijeni_redove(T** matrica, int n){
    if (n < 0) {
        throw invalid_argument("n mora biti vece od 0!");
    }

    T** temp = new T*[n];
    for(int i = 0; i < n; i+=2){
       temp[i] = matrica[i + 1];
       temp[i + 1] = matrica[i];
       }
    return temp;
}

int main() {
    int n = 4;
    if (n %2!= 0){
        throw invalid_argument("n ne smije biti neparno!");
    }
    int** matrica = new int*[n];
    int pom_br = 1;
    for (int i = 0; i < n; i++) {
        matrica[i] = new int[n];
        for (int j = 0; j < n; j++) {
            matrica[i][j] = pom_br++;
        }
    }

    cout << "Matrica prije okretanja:" << endl;
    ispisi_mat(matrica, 4);

    int** nova_matrica = zamijeni_redove(matrica, n);

    cout << endl << "Matrica nakon okretanja:" << endl;
    ispisi_mat(nova_matrica, 4);


    for (int i = 0; i < n; i++) {
        delete[] matrica[i];
    }
    delete[] matrica;

    return 0;
}
