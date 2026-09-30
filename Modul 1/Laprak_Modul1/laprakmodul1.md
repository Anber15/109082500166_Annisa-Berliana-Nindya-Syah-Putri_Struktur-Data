# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Annisa Berliana Nindya Syah Putri - 109082500166</p>

## Dasar Teori
## A. Pengenalan Bahasa C++ dan Struktur Data Program
Bahasa C++ dibuat oleh Bjarne Stroustrup di AT&T Bell Laboratories pada awal tahun 1980-an. Bahasa ini dikembangkan dari bahasa C ANSI. Pada awalnya, C++ masih berupa prototype bahasa C yang ditambahkan fasilitas kelas dan dikenal dengan istilah *C with Classes*. Setelah itu, bahasa ini terus dikembangkan dengan menambahkan beberapa fitur, seperti pembebanan operator dan fungsi, sampai akhirnya dikenal sebagai C++.

Tanda “++” pada C++ berasal dari operator kenaikan yang ada pada bahasa C. Struktur dasar program C++ terdiri dari beberapa bagian, yaitu *library* atau header file dengan `#include`, konstanta, tipe data bentukan, variabel, fungsi atau prosedur, dan fungsi utama `main()`. Setiap perintah pada C++ diakhiri dengan tanda titik koma (;). C++ juga bersifat *case sensitive*, jadi penulisan huruf besar dan huruf kecil harus diperhatikan karena dianggap berbeda.

## B. Identifier, Tipe Data, Variabel, dan Konstanta
Identifier adalah sebuah nama yang dipakai untuk membedakan variabel, konstanta, fungsi, atau objek lain dalam satu program. Penulisannya mesti dimulai dengan huruf atau garis bawah (`_`), lalu bisa dilanjutkan huruf, angka, garis bawah, atau tanda dollar (`$`). Identifier tidak boleh memakai spasi atau operator aritmatika dan punya panjang maksimal 32 karakter.

Tipe data berguna untuk menentukan macam data yang akan disimpan dalam program. Beberapa tipe data dasar di C++ adalah bilangan bulat (integer), bilangan pecahan presisi tunggal (float), bilangan pecahan presisi ganda (double), karakter (char), dan `void`. Setiap tipe data punya ukuran memori dan jangkauan nilai yang berbeda. Tipe data juga bisa memakai type modifier seperti `unsigned`, `short`, dan `long` untuk mengatur kapasitas atau jangkauan nilainya.

Variabel dipakai untuk menampung data yang nilainya bisa berubah sewaktu program berjalan. Sementara itu, konstanta dipakai untuk menampung nilai yang pasti dan tidak bisa diubah. Konstanta dideklarasikan dengan menambahkan kata kunci `const` sebelum tipe datanya.

## C. Operasi Input dan Output
Dalam C++, untuk menampilkan data ke layar digunakan `cout` yang berasal dari *namespace* `std`. Operator `<<` digunakan untuk memasukkan teks atau nilai yang ingin ditampilkan. Tampilan output juga bisa diatur menggunakan *escape sequence*, misalnya `\n` untuk membuat baris baru dan `\t` untuk memberikan jarak seperti tab. Selain itu, penentu format dan lebar *field* dapat digunakan agar hasil angka desimal terlihat lebih rapi.

Untuk menerima input dari keyboard, C++ menggunakan `cin` dengan operator `>>`. Nilai yang dimasukkan akan langsung disimpan ke dalam variabel yang sudah ditentukan. Ada juga `getchar()` yang digunakan untuk membaca satu karakter dari input. Perbedaannya, `cin` biasanya menunggu pengguna menekan tombol *Enter*, sedangkan `getchar()` membaca satu karakter yang diberikan dari input standar.

## D. Operator dan Ekspresi
Operator adalah simbol yang digunakan untuk melakukan operasi pada data dalam program. Di C++, ada beberapa jenis operator yang sering digunakan. Operator aritmatika seperti `+`, `-`, `*`, `/`, dan `%` digunakan untuk melakukan perhitungan. Ada juga operator assignment seperti `=`, `+=`, dan `-=` yang digunakan untuk memberikan atau mengubah nilai pada variabel.

Operator hubungan seperti `==`, `!=`, `<`, `>`, `<=`, dan `>=` digunakan untuk membandingkan dua nilai. Hasil perbandingan tersebut berupa benar atau salah. Sementara itu, operator logika seperti `&&`, `||`, dan `!` digunakan untuk menggabungkan atau membalik kondisi.

C++ juga memiliki operator unary, salah satunya `sizeof` yang digunakan untuk mengetahui ukuran data dalam memori dengan satuan *byte*. Kemudian ada `++` dan `--` untuk menambah atau mengurangi nilai variabel sebanyak satu. Keduanya dapat ditulis dalam bentuk *prefix*, seperti `++i`, atau *postfix*, seperti `i++`. Pada *prefix*, nilai variabel diubah terlebih dahulu sebelum digunakan, sedangkan pada *postfix*, nilai variabel digunakan terlebih dahulu baru kemudian diubah.

## E. Percabangan
**5. Percabangan**

Percabangan digunakan ketika program perlu menentukan tindakan berdasarkan suatu kondisi. Percabangan yang paling dasar adalah `if`. Jika kondisi yang diberikan bernilai benar, maka perintah di dalam `if` akan dijalankan. Jika ingin memberikan pilihan lain saat kondisi tersebut salah, dapat digunakan `if-else`.

Untuk kondisi sederhana, `if-else` juga bisa ditulis lebih singkat menggunakan *ternary operator* dengan bentuk `expr1 ? expr2 : expr3`. Sementara itu, jika terdapat beberapa pilihan yang bergantung pada satu nilai, dapat digunakan `switch`. Pada `switch`, nilai suatu variabel akan dibandingkan dengan beberapa `case`. Jika nilainya sesuai dengan salah satu `case`, perintah pada bagian tersebut akan dijalankan. Jika tidak ada yang sesuai, program akan menjalankan bagian `default`.

## F. Looping
**6. Struktur Perulangan (Looping)**

Perulangan atau *looping* digunakan untuk menjalankan perintah yang sama beberapa kali tanpa harus menulis kode yang sama berulang-ulang. Dalam perulangan harus ada kondisi yang menentukan kapan perulangan berhenti. C++ memiliki tiga jenis perulangan yang umum digunakan, yaitu `for`, `while`, dan `do...while`.

Perulangan `for` biasanya digunakan jika jumlah perulangan sudah diketahui. Di dalamnya terdapat bagian inisialisasi, kondisi, dan *increment/decrement*. `while` digunakan untuk menjalankan perintah selama kondisinya masih terpenuhi. Kondisi pada `while` dicek terlebih dahulu sebelum perintah dijalankan. Sedangkan pada `do...while`, perintah dijalankan terlebih dahulu baru kondisinya diperiksa. Jadi, perintah di dalam `do...while` tetap akan dijalankan setidaknya satu kali meskipun kondisi awalnya salah.

## G. Struct
**7. Tipe Data Bentukan (Struktur)**

`struct` merupakan tipe data bentukan yang digunakan untuk menggabungkan beberapa data dengan tipe yang berbeda ke dalam satu kelompok. Dengan `struct`, data yang saling berhubungan bisa disimpan dalam satu nama. Contohnya, data siswa dapat memiliki `nama` yang bertipe `string` dan `nilai` yang bertipe `int`.

Untuk membuat sebuah struktur, digunakan kata kunci `struct`, kemudian diikuti nama struktur dan data atau *field* yang ada di dalamnya. Setiap data di dalam struktur dapat diakses menggunakan tanda titik (`.`). `struct` juga bisa digabungkan dengan array untuk menyimpan banyak data dengan bentuk yang sama, misalnya beberapa data siswa sekaligus.

## Unguided

### Unguided 1
#### 1. Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.

#### Code Program
```C++
#include <iostream>
using namespace std;

int main() {
    float x, y;
    
    cout << "Masukkan bilangan pertama: ";
    cin >> x;
    cout << "Masukkan bilangan kedua: ";
    cin >> y;
    
    cout << "\n--- Hasil Operasi ---" << endl;
    cout << "Penjumlahan: " << x << " + " << y << " = " << x + y << endl;
    cout << "Pengurangan: " << x << " - " << y << " = " << x - y << endl;
    cout << "Perkalian: " << x << " * " << y << " = " << x * y << endl;
    
    if (y != 0) {
        cout << "Pembagian: " << x << " / " << y << " = " << x / y << endl;
    } else {
        cout << "Pembagian dengan nol tidak terdefinisi." << endl;
    }

    return 0;
}
```

#### Output Unguided 1:
##### Output 1
![Screenshot Output Unguided 1.1](https://github.com/Anber15/109082500166_Annisa-Berliana-Nindya-Syah-Putri_Struktur-Data/blob/main/Modul1/Unguided/Unguided%201/Screenshot%202026-09-30%20105443.png?raw=true)

##### Output 2
![Screenshot Output Unguided 1.2](https://github.com/Anber15/109082500166_Annisa-Berliana-Nindya-Syah-Putri_Struktur-Data/blob/main/Modul1/Unguided/Unguided%201/Screenshot%202026-09-30%20105933.png?raw=true)

#### Penjelasan Program
Program ini digunakan untuk menghitung operasi dasar dari dua bilangan, yaitu penjumlahan, pengurangan, perkalian, dan pembagian. Program meminta pengguna memasukkan dua bilangan yang disimpan dalam variabel `x` dan `y` dengan tipe `float`.

Setelah itu, program menghitung dan menampilkan hasil dari setiap operasi. Pada pembagian, digunakan `if-else` untuk mengecek apakah nilai `y` sama dengan nol. Jika `y` bukan nol, pembagian dilakukan. Jika `y` sama dengan nol, program menampilkan pesan bahwa pembagian dengan nol tidak terdefinisi.

### Unguided 2
#### 2. Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di-input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100

#### Code Program
```C++
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
```

#### Output Unguided 2:
##### Output 1
![Screenshot Output Unguided 2.1](https://github.com/Anber15/109082500166_Annisa-Berliana-Nindya-Syah-Putri_Struktur-Data/blob/main/Modul1/Unguided/Unguided%202/Screenshot%202026-09-30%20112728.png?raw=true)

##### Output 2
![Screenshot Output Unguided 2.2](https://github.com/Anber15/109082500166_Annisa-Berliana-Nindya-Syah-Putri_Struktur-Data/blob/main/Modul1/Unguided/Unguided%202/Screenshot%202026-09-30%20112755.png?raw=true)

##### Output 3
![Screenshot Output Unguided 2.3](https://github.com/Anber15/109082500166_Annisa-Berliana-Nindya-Syah-Putri_Struktur-Data/blob/main/Modul1/Unguided/Unguided%202/Screenshot%202026-09-30%20112821.png?raw=true)

#### Penjelasan Program
Program ini digunakan untuk mengubah angka dari 0 sampai 100 menjadi bentuk tulisan dalam bahasa Indonesia. Pengguna memasukkan angka yang disimpan dalam variabel `n`.

Program menggunakan array `satuan` untuk menyimpan nama angka dari nol sampai sebelas. Setelah itu, digunakan percabangan `if-else` untuk menentukan tulisan yang sesuai. Angka 0 akan menghasilkan `"nol"`, sedangkan 100 menghasilkan `"seratus"`. Untuk angka 1–11, program mengambil data langsung dari array `satuan`. Angka 12–19 diubah menjadi bentuk `"belas"`, sedangkan angka 20–99 dipisahkan menjadi bagian puluhan dan satuan menggunakan operasi `/` dan `%`.

Jika angka yang dimasukkan berada di luar rentang 0–100, program akan menampilkan pesan `"Angka di luar jangkauan!"`.

### Unguided 3
#### 3. Buatlah program yang dapat memberikan input dan output sbb.

#### Code Program
```C++
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "input: ";
    cin >> n;
    cout << "output:" << endl;

    for (int i = n; i >= 1; i--) {

        for (int j = 0; j < n - i; j++) {
            cout << "  ";
        }

        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }
        
        cout << "* ";
        
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }

    for (int j = 0; j < n; j++) {
        cout << "  ";
    }
    cout << "*" << endl;

    return 0;
}
```

#### Output Unguided 3:
##### Output 1
![Screenshot Output Unguided 3.1](https://github.com/Anber15/109082500166_Annisa-Berliana-Nindya-Syah-Putri_Struktur-Data/blob/main/Modul1/Unguided/Unguided%203/Screenshot%202026-09-30%20193639.png?raw=true)

##### Output 2
![Screenshot Output Unguided 3.2](https://github.com/Anber15/109082500166_Annisa-Berliana-Nindya-Syah-Putri_Struktur-Data/blob/main/Modul1/Unguided/Unguided%203/Screenshot%202026-09-30%20193652.png?raw=true)

#### Penjelasan Program
Program ini digunakan untuk membuat pola angka berbentuk seperti segitiga dengan tanda `*` di bagian tengah. Pengguna memasukkan nilai `n` sebagai ukuran pola.

Perulangan `for` pertama digunakan untuk membuat baris dari `n` sampai 1. Di dalamnya terdapat perulangan untuk mengatur jarak di sebelah kiri, kemudian menampilkan angka secara menurun, tanda `*`, dan angka secara menaik. Setelah semua baris selesai, perulangan terakhir digunakan untuk menampilkan tanda `*` di bagian paling bawah pola.

## Kesimpulan
Berdasarkan praktikum yang telah dilakukan, dapat disimpulkan bahwa lingkungan pengembangan Code Blocks IDE dapat digunakan dengan baik untuk menulis, meng-compile, dan menjalankan program bahasa C++. Dalam praktikum ini, saya memahami struktur dasar pemrograman C++ yang meliputi pendeklarasian library, variabel, konstanta, serta penggunaan tipe data dasar seperti integer, float, dan char. Selain itu, saya berhasil mengimplementasikan operasi input dan output menggunakan cin dan cout, serta menerapkan berbagai jenis operator aritmatika, logika, dan unary. Melalui latihan yang diberikan, saya juga memahami cara mengontrol alur program menggunakan pernyataan kondisional (if-else, switch) dan struktur perulangan (for, while, do-while) untuk menyelesaikan permasalahan seperti konversi angka ke tulisan dan pembuatan pola mirror.

## Referensi
[1] Tim Asisten Praktikum. (t.t.). Modul 1: Code Blocks IDE & Pengenalan Bahasa C++ (Bagian Pertama). Telkom University.
[2] Indahyanti, Uce., & Rahmawati Yunianita. (2020). Buku Ajar Algoritma Dan Pemrograman Dalam Bahasa C++. Sidoarjo: Umsida Press.