#include <iostream>
#include <algorithm>
#include <stdexcept>

using namespace std;

int* unija(int* niz1, int n1, int* niz2, int n2, int& duzinaRezultata) {
    if (n1 <= 0 || n2 <= 0) {
        throw invalid_argument("Duzina niza ne smije biti 0!");
    }

    int* niz1_copy = new int[n1];
    int* niz2_copy = new int[n2];

    copy(niz1, niz1 + n1, niz1_copy);
    copy(niz2, niz2 + n2, niz2_copy);

    sort(niz1_copy, niz1_copy + n1);
    sort(niz2_copy, niz2_copy + n2);

    int* unija_arr = new int[n1 + n2];
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (niz1_copy[i] == niz2_copy[j]) {
            unija_arr[k++] = niz1_copy[i++];
            j++;
        } else if (niz1_copy[i] < niz2_copy[j]) {
            unija_arr[k++] = niz1_copy[i++];
        } else {
            unija_arr[k++] = niz2_copy[j++];
        }
    }

    while (i < n1) {
        unija_arr[k++] = niz1_copy[i++];
    }
    while (j < n2) {
        unija_arr[k++] = niz2_copy[j++];
    }
    duzinaRezultata = unique(unija_arr, unija_arr + k) - unija_arr;

    delete[] niz1_copy;
    delete[] niz2_copy;

    return unija_arr;
}

int main() {
    int n1, n2, duzina_rezultata;
    n1 = 8;
    n2 = 5;
    int test_niz1[] = {2, 5, 1, 2, 4, 5, 7, 1};
    int test_niz2[] = {7, 3, 2, 1, 6};
    int* unija_arr = unija(test_niz1, n1, test_niz2, n2, duzina_rezultata);
    for (int i = 0; i < duzina_rezultata; i++) {
        cout << unija_arr[i] << " ";
    }
    delete[] unija_arr;
    return 0;
}
