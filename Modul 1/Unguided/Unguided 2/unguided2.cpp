#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cout << "Masukkan angka (0-100): ";
    cin >> n;

    string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan", "sepuluh", "sebelas"};

    if (n == 0) {
        cout << "nol" << endl;
    }
    else if (n == 100) {
        cout << "seratus" << endl;
    }
    else if (n < 12) {
        cout << satuan[n] << endl;
    }
    else if (n < 20) {
        cout << satuan[n-10] << " belas" << endl;
    }
    else if (n < 100) {
        int p = n / 10;
        int s = n % 10;
        
        string puluhan[] = {"", "", "dua puluh", "tiga puluh", "empat puluh", "lima puluh", "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};

        cout << puluhan[p];
        if (s > 0) {
            cout << " " << satuan[s];
        }
        cout << endl;
    }
    else {
        cout << "Angka di luar jangkauan!" << endl;
    }

    return 0;
}