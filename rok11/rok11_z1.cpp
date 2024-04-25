#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int najduzi_rastuci(vector<string>& v) {
    int n = v.size();

    if (n == 0) return 0;
    if (n == 1) return 1;

    int najduza = 1;
    int trenutna = 1;

    for (int i = 1; i < n; i++) {
        if (v[i] > v[i - 1]) {
            trenutna++;
        } else {
            najduza = max(najduza, trenutna);
            trenutna = 1;
        }
    }
    return max(najduza, trenutna);
}

int main() {
    vector<string> niz = {"aaa", "bb", "c", "aac", "bbc", "bcc", "bcd", "bxx", "aa", "ggg", "xyz"};

    cout << najduzi_rastuci(niz) << endl;
    return 0;
}
