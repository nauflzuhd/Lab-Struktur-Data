#include <iostream> //library untuk input output
#include <vector> //library untuk vector
using namespace std; //agar tidak perlu menulis std:: pada code

//fungsi untuk menggabungkan dua bagian array yang sudah terurut
void merge(vector<int>& arr, int left, int mid, int right) {
   
    int n1 = mid - left + 1;  // panjang array kiri 
    int n2 = right - mid; // panjang array kanan


    vector<int> L(n1), R(n2); //membuat dua vector untuk menyimpan bagian kiri dan kanan

    //copy data dari array ke vector L dan R
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];      //perulangan untuk mengisi array bagian kiri ke L
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];   //perulangan untuk mengisi array bagian kanan R


    int i = 0;      //indeks untuk L
    int j = 0;      //indeks untuk R
    int k = left;   // indeks untuk arr

    //penggabungan dua bagian yang sudah terurut
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) { //jika nilai dari L kurang atau sama dengan dari R maka
            arr[k] = L[i];  //isi nilai arr dengan nilai L
            i++;            //increment indeks L
        } else {            //jika nilai dari L lebih dari R maka
            arr[k] = R[j];  //isi nilai arr dengan nilai K
            j++;            //increment indeks R
        }
        k++; //increment indeks arr
    }

    //menyalin sisa dari elemen L
    while (i < n1) {
        arr[k] = L[i];  //isi nilai arr dengan nilai L
        i++;            //increment indeks L
        k++;            //increment indeks arr
    }

    //menyalin sisa dari elemen R
    while (j < n2) {
        arr[k] = R[j];  //isi nilai arr dengan nilai R
        j++;            //increment indeks R
        k++;            //increment indeks arr
    }
}

// Fungsi utama merge sort (rekursif)
void mergeSort(vector<int>& arr, int left, int right) {
   
    if (left >= right)
        return;         //return jika hanya satu elemen, tidak perlu diurutkan


    int mid = left + (right - left) / 2; //menghitung indeks tengah


    mergeSort(arr, left, mid);      //rekursi bagian kiri
    mergeSort(arr, mid + 1, right); //rekursi bagian kanan
   
    merge(arr, left, mid, right);  // memanggil fungsi merge untuk menggabungkan dua bagian yang sudah terurut
}

//fungsi untuk mencetak array
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " "; //perulangan untuk mencetak isi array
    }
    cout << endl; // pindah baris
}

//main program
int main() {
    int n; //deklarasi variabel n
    cout << "Masukkan jumlah elemen data: "; //output Masukkan jumlah elemen data:
    cin >> n; //input n (jumlah elemen data)
   
    vector<int> data(n); //buat vector dengan nama data berukuran n
    cout << "Masukkan elemen-elemen data: "; //output Masukkan elemen-elemen data:
    for (int i = 0; i < n; i++) {
        cin >> data[i]; //perulangan untuk input nilai ke data
    }
   
    cout << "Array sebelum diurutkan: "; //output Array sebelum diurutkan:
    printArray(data); //mencetak array dengan memanggil fungsi printArray
   
    mergeSort(data, 0, n - 1); //mengurutkan data dengan memanggil fungsi mergeSort
   
    cout << "Array setelah diurutkan: "; //output Array setelah diurutkan:
    printArray(data); //mencetak array setelah diurutkan dengan memanggil fungsi printArray
   
    return 0; //akhir program /selesai
}