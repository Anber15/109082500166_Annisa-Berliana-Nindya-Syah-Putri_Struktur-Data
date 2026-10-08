# <h1 align="center">Laporan Praktikum Modul 3 - Pengenalan Bahasa C++ (Bagian Kedua)</h1>
<p align="center">Annisa Berliana Nindya Syah Putri - 109082500166</p>

## Dasar Teori
### A. Array<br/> 
Array adalah struktur data yang terdiri dari kumpulan elemen dengan nama dan tipe data yang sama, yang disimpan secara berurutan di dalam memori. Setiap elemen dalam array diakses menggunakan indeks, di mana indeks pertama selalu dimulai dari angka 0. Berdasarkan dimensinya, array terbagi menjadi array satu dimensi yang hanya terdiri dari satu larik data, array dua dimensi yang strukturnya menyerupai tabel dengan baris dan kolom, serta array berdimensi banyak yang memiliki lebih dari dua indeks untuk merepresentasikan data yang lebih kompleks. Penggunaan array sangat efektif untuk menyimpan dan mengelola sekumpulan data dalam jumlah besar tanpa perlu mendeklarasikan banyak variabel secara terpisah.

### B. Data dan Memori
Dalam pemrograman komputer, semua data yang digunakan oleh program disimpan di dalam memori (RAM). Memori dapat digambarkan sebagai sebuah array satu dimensi yang berukuran sangat besar, di mana setiap sel memori memiliki "indeks" atau alamat unik yang disebut sebagai address. Saat program berjalan, Sistem Operasi (OS) akan mengalokasikan ruang memori untuk setiap variabel, objek, atau array yang dibuat. Lokasi pengalokasian memori ini bisa sangat teracak tergantung pada proses di dalam OS. Untuk mengetahui alamat memori di mana suatu variabel dialokasikan, programmer dapat menggunakan operator address-of (&) yang ditempatkan di depan nama variabel.

### C. Pointer dan Alamat
Variabel pointer adalah tipe variabel khusus yang digunakan untuk menyimpan alamat memori dari variabel lain, bukan menyimpan nilai datanya secara langsung. Nilai yang disimpan dalam pointer biasanya berupa bilangan dalam format heksadesimal. Pointer dideklarasikan menggunakan tanda bintang (*) di depan nama variabel. Agar sebuah pointer dapat menunjuk ke variabel lain, pointer tersebut harus diisi dengan alamat memori variabel tujuan menggunakan operator &. Untuk mendapatkan atau mengubah nilai dari variabel yang ditunjuk oleh pointer, digunakan operator dereference (*) di depan nama pointer. Karena pointer juga merupakan variabel, ia pun akan menggunakan ruang memori dan memiliki alamatnya sendiri.

### D. Pointer dan String
Dalam bahasa C++, string pada dasarnya merupakan kumpulan dari karakter atau array dari karakter yang selalu diakhiri dengan karakter null (\0) sebagai penanda akhir string. Pointer sangat erat kaitannya dengan string karena konstanta string akan diakses oleh pointer mulai dari elemen pertama (alamat awal array karakter). Terdapat perbedaan mendasar antara mendeklarasikan string sebagai array karakter (misalnya char amessage[] = "teks") dan sebagai pointer karakter (misalnya char *pmessage = "teks"). Array karakter bersifat mutable (dapat diubah per karakternya) dan ukurannya tetap, sedangkan pointer karakter hanya menyimpan alamat dari konstanta string; pointer tersebut dapat diubah untuk menunjuk ke string lain, namun isi dari string konstanta yang ditunjuknya tidak boleh diubah.

### E. Fungsi dan Prosedur
Fungsi merupakan blok kode program yang dirancang untuk melaksanakan tugas khusus dengan tujuan agar program menjadi lebih terstruktur, mudah dipahami, dan mengurangi duplikasi kode. Fungsi umumnya memerlukan masukan berupa parameter dan akan menghasilkan sebuah nilai balik (return value) sesuai dengan tipe data yang didefinisikan. Sementara itu, dalam bahasa C++, tidak ada istilah prosedur secara eksplisit seperti pada bahasa Pascal. Prosedur di C++ diimplementasikan sebagai fungsi void, yaitu fungsi yang tidak mengembalikan nilai balik kepada pemanggilnya dan hanya menjalankan serangkaian perintah atau tugas tertentu di dalam blok kodenya.

### F. Parameter Formal dan Parameter Aktual
Dalam penggunaan fungsi atau prosedur, terdapat dua jenis parameter yang perlu dibedakan, yaitu parameter formal dan parameter aktual. Parameter formal adalah variabel yang didefinisikan di dalam daftar parameter saat fungsi atau prosedur dibuat (didefinisikan). Variabel ini akan menampung nilai yang dikirimkan saat fungsi dipanggil. Sebaliknya, parameter aktual adalah nilai, variabel, atau ungkapan yang dikirimkan atau dilewatkan ke dalam fungsi saat fungsi tersebut dipanggil di dalam program utama. Parameter aktual tidak harus selalu berupa variabel, melainkan bisa juga berupa konstanta atau hasil dari suatu ekspresi.

### G. Mekanisme Melewatkan Parameter (Call by Value, Pointer, dan Reference)
Terdapat tiga metode utama dalam melewatkan parameter ke dalam fungsi. Pertama adalah Call by Value (pemanggilan dengan nilai), di mana nilai dari parameter aktual disalin ke parameter formal. Dengan metode ini, perubahan nilai pada parameter formal di dalam fungsi tidak akan mengubah nilai variabel aktual di luar fungsi. Kedua adalah Call by Pointer (pemanggilan dengan pointer), yang melewatkan alamat memori variabel aktual menggunakan operator &. Di dalam fungsi, nilai variabel asli dapat diubah menggunakan operator dereference (*), sehingga perubahan akan berdampak langsung pada variabel aktual. Ketiga adalah Call by Reference (pemanggilan dengan referensi), yang juga melewatkan alamat memori namun menggunakan operator reference (&) pada definisi parameter formal. Metode ini memungkinkan perubahan nilai variabel aktual secara langsung di dalam fungsi tanpa perlu menggunakan operator & atau * saat pemanggilan maupun di dalam blok fungsi, menjadikannya lebih ringkas dibandingkan call by pointer.

## Guided
### Guided 1
#### 1. Array
##### Code Program
```C++
#include <iostream> //dimensi 1
using namespace std;

int main() {
    int nilai[5];

    nilai[0] = 80;
    nilai[1] = 75;
    nilai[2] = 90;
    nilai[3] = 85;
    nilai[4] = 95;

    for (int i = 0; i < 5; i++) {
        cout << "Nilai ke-" << i + 1 << " = "
            << nilai[i] << endl;
    }

    return 0;
}
```

##### Penjelasan Program
Program ini digunakan untuk menyimpan dan menampilkan beberapa nilai menggunakan array satu dimensi. Array `nilai[5]` digunakan untuk menyimpan 5 data nilai, yaitu 80, 75, 90, 85, dan 95.

Setiap nilai dimasukkan ke dalam array berdasarkan indeks yang dimulai dari 0. Setelah itu, digunakan perulangan `for` untuk menampilkan semua nilai tersebut. Variabel `i` digunakan sebagai indeks array, sedangkan `i + 1` digunakan agar nomor nilai yang ditampilkan dimulai dari 1.

### Guided 2
#### 2. Array 2D
##### Code Program
```C++
#include <iostream>
using namespace std;

int main() {
    int nilai[3][3] = {
        {80, 75, 90},
        {85, 90, 88},
        {70, 80, 85}
    };

    // Menampilkan array 2 dimensi
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << nilai[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << nilai[1][2] << endl;

    return 0;
}
```

##### Penjelasan Program
Program ini digunakan untuk membuat dan menampilkan array dua dimensi. Array `nilai[3][3]` memiliki 3 baris dan 3 kolom yang berisi nilai-nilai yang sudah ditentukan.

Untuk menampilkan semua isi array, digunakan dua perulangan `for`. Perulangan pertama menggunakan `i` untuk mengatur baris, sedangkan perulangan kedua menggunakan `j` untuk mengatur kolom. Setelah semua data ditampilkan, `nilai[1][2]` digunakan untuk mengambil nilai pada baris indeks 1 dan kolom indeks 2, yaitu `88`. Indeks pada array dimulai dari 0, sehingga baris dan kolom pertama memiliki indeks 0.

### Guided 3
#### 3. Array 3D
##### Code Program
```C++
#include <iostream>
using namespace std;

int main() {
    // Format array 3 dimensi:
    // nama_array[jumlah array 2D][jumlah baris][jumlah kolom]
    int data[2][2][3] = {
        {
            {10, 20, 30},
            {40, 50, 60}
        },
        {
            {70, 80, 90},
            {100, 110, 120}
        }
    };

    cout << data[0][1][2] << endl;

    return 0;
}
```

##### Penjelasan Program
Program ini digunakan untuk membuat array tiga dimensi yang bernama `data`. Array tersebut memiliki 2 kelompok array 2 dimensi, setiap kelompok memiliki 2 baris dan 3 kolom.

Data pada array diisi dengan beberapa nilai mulai dari 10 sampai 120. Perintah `data[0][1][2]` digunakan untuk mengambil data pada kelompok pertama, baris kedua, dan kolom ketiga. Karena indeks array dimulai dari 0, maka hasil yang ditampilkan adalah `60`.

### Guided 4
#### 4. Function
##### Code Program
```C++
#include <iostream>
using namespace std;

int maks3(int a, int b, int c) {
    int temp_max = a;

    if (b > temp_max) {
        temp_max = b;
    }

    if (c > temp_max) {
        temp_max = c;
    }

    return temp_max;
}

int main() {
    int x, y, z;

    cout << "Masukkan nilai 1 : ";
    cin >> x;

    cout << "Masukkan nilai 2 : ";
    cin >> y;

    cout << "Masukkan nilai 3 : ";
    cin >> z;

    cout << "Nilai Maksimum: " << maks3(x, y, z);

    return 0;
}
```

##### Penjelasan Program
Program ini digunakan untuk mencari nilai terbesar dari tiga bilangan. Fungsi `maks3()` menerima tiga nilai, yaitu `a`, `b`, dan `c`. Nilai `a` digunakan sebagai nilai awal pada variabel `temp_max`, kemudian dibandingkan dengan `b` dan `c`. Jika ada nilai yang lebih besar, maka `temp_max` akan diperbarui.

Pada fungsi `main()`, pengguna memasukkan tiga bilangan yang disimpan dalam variabel `x`, `y`, dan `z`. Ketiga nilai tersebut kemudian dikirim ke fungsi `maks3()` untuk dicari nilai terbesarnya. Hasilnya ditampilkan dengan tulisan `Nilai Maksimum`.

### Guided 5
#### 5. Procedure
##### Code Program
```C++
#include <iostream>
using namespace std;

void sapa(){
    cout<<"Selamat datang di Praktikum Struktur data" << endl;
}

int main(){
    sapa();
    return 0;
}
```

##### Penjelasan Program

### Guided 6
#### 6. Pointer 1
##### Code Program 
```C++
#include <iostream>
using namespace std;

int main(){
    int angka = 100;

    cout<<"Nilai variabel angka: "<< angka << endl;
    cout<<"Alamat variabel angka: "<< &angka << endl;

    return 0;
}
```

##### Penjelasan Program
Program ini digunakan untuk menampilkan nilai dan alamat memori dari sebuah variabel. Variabel `angka` memiliki nilai `100`, kemudian `cout` digunakan untuk menampilkan nilainya. Tanda `&` pada `&angka` digunakan untuk mengambil alamat memori tempat variabel `angka` disimpan. Alamat yang muncul dapat berbeda setiap kali program dijalankan.

### Guided 7
#### 7. Pointer 2
##### Code Program 
```C++
#include <iostream>
using namespace std;

int main() {
    int angka = 100;

    cout << "Nilai variabel angka: " << angka << endl;
    cout << "Alamat variabel angka: " << &angka << endl;

    return 0;
}
```

##### Penjelasan Program
Program ini digunakan untuk menampilkan nilai dan alamat dari sebuah variabel. Variabel `angka` bertipe `int` dan memiliki nilai `100`.

Perintah `cout << angka` digunakan untuk menampilkan nilai dari variabel tersebut. Sedangkan `&angka` digunakan untuk mendapatkan alamat memori tempat variabel `angka` disimpan. Alamat yang ditampilkan bisa berbeda-beda setiap kali program dijalankan.

### Guided 8
#### 8. Pointer Array
##### Code Program
```C++
#include <iostream>
using namespace std;

int main() {
    char arr[6];

    arr[0] = 'a';
    arr[1] = 'b';
    arr[2] = 'c';
    arr[3] = 'b';
    arr[4] = 'd';
    arr[5] = 'e';

    cout << arr[3] << endl;        // Menampilkan nilai
    cout << &(arr[4]) << endl;     // Menampilkan alamat memori

    return 0;
}
```

##### Penjelasan Program
Program ini membuat array karakter bernama `arr` yang memiliki 6 elemen. Setiap elemen diisi dengan karakter dari `a` sampai `e`, dengan karakter `b` yang muncul dua kali.

Perintah `arr[3]` digunakan untuk mengambil nilai pada indeks ke-3, sehingga hasilnya adalah `b`. Sedangkan `&(arr[4])` digunakan untuk mengambil alamat memori dari elemen pada indeks ke-4. Karena indeks array dimulai dari 0, `arr[4]` berisi karakter `d`.

### Guided 9
#### 9. Call by Pointer Reference Value
##### Code Program
```C++
#include <iostream>
using namespace std;

// By Pointer
void tukarPointer(int *x, int *y) {
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

// By Reference
void tukarReference(int &x, int &y) {
    int temp;

    temp = x;
    x = y;
    y = temp;
}

// By Value
void tukarValue(int x, int y) {
    int temp;

    temp = x;
    x = y;
    y = temp;
}

int main() {
    int a, b;

    // By Pointer
    a = 4;
    b = 6;

    cout << "=== By Pointer ===" << endl;
    cout << "Sebelum ditukar: a = " << a << ", b = " << b << endl;

    tukarPointer(&a, &b);

    cout << "Setelah ditukar: a = " << a << ", b = " << b << endl;

    // By Reference
    a = 4;
    b = 6;

    cout << "\n=== By Reference ===" << endl;
    cout << "Sebelum ditukar: a = " << a << ", b = " << b << endl;

    tukarReference(a, b);

    cout << "Setelah ditukar: a = " << a << ", b = " << b << endl;

    // By Value
    a = 4;
    b = 6;

    cout << "\n=== By Value ===" << endl;
    cout << "Sebelum ditukar: a = " << a << ", b = " << b << endl;

    tukarValue(a, b);

    cout << "Setelah ditukar: a = " << a << ", b = " << b << endl;

    return 0;
}
```

##### Penjelasan Program
Program ini membandingkan tiga cara mengirimkan nilai ke fungsi, yaitu *by pointer*, *by reference*, dan *by value*. Pada *by pointer*, alamat variabel dikirim menggunakan `&` dan nilainya diakses dengan `*`. Pada *by reference*, fungsi langsung menggunakan variabel aslinya sehingga nilainya dapat berubah. Sedangkan pada *by value*, yang dikirim hanya salinan nilai sehingga perubahan di dalam fungsi tidak memengaruhi variabel asli. Karena itu, hasil *by pointer* dan *by reference* membuat nilai `a` dan `b` tertukar, sedangkan *by value* tetap menghasilkan `a = 4` dan `b = 6`.

## Unguided
### Unguided 1
#### 1. Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3
##### Code Program
```C++
#include <iostream>
using namespace std;

int main() {
    int A[3][3], B[3][3];
    int tambah[3][3];
    int kurang[3][3];
    int kali[3][3] = {0};

    cout << "Input Matriks A" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "A[" << i << "][" << j << "] : ";
            cin >> A[i][j];
        }
    }

    cout << "\nInput Matriks B" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "B[" << i << "][" << j << "] : ";
            cin >> B[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tambah[i][j] = A[i][j] + B[i][j];
            kurang[i][j] = A[i][j] - B[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                kali[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "\nHasil Penjumlahan:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << tambah[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nHasil Pengurangan:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << kurang[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nHasil Perkalian:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << kali[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
```

##### Output Unguided 1
![Screenshot Output Unguided 1](https://github.com/Anber15/109082500166_Annisa-Berliana-Nindya-Syah-Putri_Struktur-Data/blob/main/Modul%202/Unguided/Unguided%201/Screenshot%202026-10-08%20213801.png)

##### Penjelasan Program
Program ini digunakan untuk melakukan penjumlahan, pengurangan, dan perkalian pada dua matriks berukuran 3×3. Pertama, pengguna diminta memasukkan nilai untuk matriks `A` dan `B`, kemudian data tersebut disimpan ke dalam array dua dimensi.

Penjumlahan dan pengurangan dilakukan dengan menjumlahkan atau mengurangi nilai pada posisi baris dan kolom yang sama. Untuk perkalian matriks, digunakan tiga perulangan `for` karena setiap nilai pada hasil perkalian diperoleh dari perkalian dan penjumlahan beberapa elemen dari matriks `A` dan `B`. Setelah semua proses selesai, hasil dari ketiga operasi ditampilkan ke layar.

### Unguided 2
#### 2. Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel 
##### Code Program
```C++
#include <iostream>
using namespace std;

void pointer(int *a, int *b, int *c) {
    int temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}

void reference(int &a, int &b, int &c) {
    int temp = a;
    a = b;
    b = c;
    c = temp;
}

int main() {
    int a = 10, b = 20, c = 30;

    cout << "Sebelum ditukar:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    pointer(&a, &b, &c);

    cout << "\nPointer:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    a = 10;
    b = 20;
    c = 30;

    reference(a, b, c);

    cout << "\nReference:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    return 0;
}
```
###### Output Unguided 2:
![Screenshot Output Unguided 2](https://github.com/Anber15/109082500166_Annisa-Berliana-Nindya-Syah-Putri_Struktur-Data/blob/main/Modul%202/Unguided/Unguided%202/Screenshot%202026-10-08%20214214.png)

###### Penjelasan Program
Program ini digunakan untuk menukar nilai dari tiga variabel menggunakan pointer dan reference. Pada pointer, nilai variabel diakses melalui alamat menggunakan `*`, sedangkan pada reference variabel dapat langsung digunakan.

Nilai awal `a`, `b`, dan `c` adalah 10, 20, dan 30. Setelah ditukar, nilai `a` menjadi 20, `b` menjadi 30, dan `c` menjadi 10. Kedua cara tersebut menghasilkan nilai yang sama, tetapi cara penggunaannya berbeda.


### Unguided 3
#### 3. Diketahui sebuah array 1 dimensi sebagai berikut: arrA = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55} Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata–rata dari array tersebut! Gunakan function cariMinimum() untuk mencari nilai minimum dan function cariMaksimum() untuk mencari nilai maksimum, serta gunakan prosedur hitungRataRata() untuk menghitung nilai rata–rata! Buat program menggunakan menu switch-case seperti berikut ini :
### --- Menu Program Array ---
### • Tampilkan isi array
### • cari nilai maksimum
### • cari nilai minimum
### • Hitung nilai rata - rata

##### Code Program
```C++
#include <iostream>
using namespace std;

int cariMinimum(int arr[], int n) {
    int min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    return min;
}

int cariMaksimum(int arr[], int n) {
    int max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

void hitungRataRata(int arr[], int n) {
    int total = 0;

    for (int i = 0; i < n; i++) {
        total += arr[i];
    }

    cout << "Nilai rata-rata = " << (float) total / n << endl;
}

int main() {
    int arrA[10] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int pilihan;

    do {
        cout << "\n--- Menu Program Array ---" << endl;
        cout << "1. Tampilkan isi array" << endl;
        cout << "2. Cari nilai maksimum" << endl;
        cout << "3. Cari nilai minimum" << endl;
        cout << "4. Hitung nilai rata-rata" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Isi array: ";
                for (int i = 0; i < 10; i++) {
                    cout << arrA[i] << " ";
                }
                cout << endl;
                break;

            case 2:
                cout << "Nilai maksimum = "
                     << cariMaksimum(arrA, 10) << endl;
                break;

            case 3:
                cout << "Nilai minimum = "
                     << cariMinimum(arrA, 10) << endl;
                break;

            case 4:
                hitungRataRata(arrA, 10);
                break;

            case 0:
                cout << "Program selesai." << endl;
                break;

            default:
                cout << "Pilihan tidak tersedia." << endl;
        }

    } while (pilihan != 0);

    return 0;
}
```

##### Output Unguided 3
![Screenshot Output Unguided 3](https://github.com/Anber15/109082500166_Annisa-Berliana-Nindya-Syah-Putri_Struktur-Data/blob/main/Modul%202/Unguided/Unguided%203/Screenshot%202026-10-08%20214510.png)

##### Penjelasan Program
Program ini digunakan untuk mencari nilai minimum, maksimum, dan rata-rata dari array `arrA` yang berisi 10 nilai. Program menggunakan menu `switch-case` agar pengguna dapat memilih operasi yang ingin dilakukan.

Function `cariMinimum()` digunakan untuk mencari nilai terkecil dan `cariMaksimum()` untuk mencari nilai terbesar. Sedangkan `hitungRataRata()` digunakan untuk menjumlahkan seluruh isi array lalu membaginya dengan jumlah data. Menu juga menyediakan pilihan untuk menampilkan isi array atau keluar dari program.

## Kesimpulan
Program ini digunakan untuk menampilkan nilai dan alamat memori dari sebuah variabel. Variabel `angka` memiliki nilai `100`, kemudian `cout` digunakan untuk menampilkan nilainya. Tanda `&` pada `&angka` digunakan untuk mengambil alamat memori tempat variabel `angka` disimpan. Alamat yang muncul dapat berbeda setiap kali program dijalankan.

## Referensi
Modul 2: PENGENALAN BAHASA C++ (BAGIAN KEDUA). Modul Praktikum Struktur Data. (Referensi Modul). 
<br>Munir, R. (2013). Algoritma dan Pemrograman dalam Bahasa Pascal dan C. Bandung: Informatika.