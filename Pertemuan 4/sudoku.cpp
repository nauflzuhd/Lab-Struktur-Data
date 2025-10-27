/*
Nama: Muhammad Naufal Zuhdi
NIM: 241401052
*/

#include <iostream>
#include <vector>

using namespace std;

// Fungsi untuk mencetak papan Sudoku
void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
            if ((j + 1) % 3 == 0) {
                cout << " ";
            }
        }
        cout << endl;
        if ((i + 1) % 3 == 0) {
            cout << endl;
        }
    }
}

// Fungsi untuk memeriksa apakah sebuah angka valid di posisi tertentu
bool isValid(const vector<vector<int>>& board, int row, int col, int num) {
    // periksa baris dan kolom
    for (int i = 0; i < 9; i++) {
        // cek pada garis horizontal dan vertikal apakah ada yang bernilai sama
        if (board[row][i] == num || board[i][col] == num) {
            // jika ada maka return false
            return false;
        }
    }

    // Periksa sub-kotak 3x3
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    // cek sub-kotak 3x3 apakah ada yang bernilai sama
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) {
                // jika ada maka return false
                return false;
            }
        }
    }
    // return true jika semuanya memenuhi syarat
    return true;
}

// Fungsi utama pemecah Sudoku menggunakan rekursif DFS
bool solveSudoku(vector<vector<int>>& board) {
    // iterasi melalui setiap baris dari papan Sudoku
    for (int i = 0; i < 9; i++) {
        // iterasi melalui setiap kolom dari papan Sudoku
        for (int j = 0; j < 9; j++) {
            // cek apakah sel saat ini kosong (bernilai 0)
            if (board[i][j] == 0) {
                // coba masukkan angka dari 1 hingga 9 ke dalam sel kosong
                for (int num = 1; num <= 9; num++) {
                    // periksa apakah angka tersebut valid di posisi (i, j)
                    if (isValid(board, i, j, num)) {
                        // jika valid, masukkan angka ke dalam sel
                        board[i][j] = num;
                        // lakukan rekursi untuk mencoba mengisi sel kosong berikutnya
                        if (solveSudoku(board)) {
                            // jika rekursi berhasil menemukan solusi, return true
                            return true;
                        }  
                        // jika rekursi gagal (tidak menemukan solusi dengan angka ini),
                        // kosongkan kembali sel tersebut (backtracking)
                        board[i][j] = 0;
                    }
                }
                // jika tidak ada angka dari 1-9 yang valid untuk sel ini, return false
                // ini memicu backtracking ke sel sebelumnya
                return false;
            }
        }
    }
    // jika semua sel terisi, return true
    return true;
}

int main() {
    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    

    cout << "Papan Sudoku awal:" << endl;
    printBoard(board);

    if (solveSudoku(board)) {
        cout << "Papan Sudoku terpecahkan:" << endl;
        printBoard(board);
    } else {
        cout << "Tidak ada solusi yang ditemukan." << endl;
    }

    return 0;
}