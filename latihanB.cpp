#include <iostream>
#include <string>
using namespace std;

// Class Buku untuk menyimpan informasi buku
class Buku {
private:
    string judul;
    string penulis;
    bool dipinjam; // Status peminjaman, privat

public:
    Buku(string j, string p) : judul(j), penulis(p), dipinjam(false) {}

    // Fungsi untuk melihat status peminjaman
    bool getDipinjam() const {
        return dipinjam;
    }

    // Friend class Petugas agar bisa mengubah status peminjaman
    friend class Petugas;
    
    // Friend class Admin agar bisa melihat data buku
    friend class Admin;
};

// Class Peminjaman untuk menyimpan informasi peminjaman
class Peminjaman {
private:
    string nama;
    int id;
    int jumlahBukuDipinjam;
    int totalPinjaman;

public:
    Peminjaman(string n, int i) : nama(n), id(i), jumlahBukuDipinjam(0), totalPinjaman(0) {}

    // Friend class Petugas agar bisa mengubah total pinjaman
    friend class Petugas;

    // Friend class Admin agar bisa mengakses data peminjaman
    friend class Admin;

    // Fungsi untuk menambah jumlah buku yang dipinjam
    void tambahBuku(int jumlah) {
        jumlahBukuDipinjam += jumlah;
        totalPinjaman += jumlah;
    }

    // Fungsi untuk mendapatkan jumlah buku yang dipinjam
    int getJumlahBuku() const {
        return jumlahBukuDipinjam;
    }

    // Fungsi untuk melihat total pinjaman
    int getTotalPinjaman() const {
        return totalPinjaman;
    }

    // Fungsi untuk melihat nama peminjam
    string getNama() const {
        return nama;
    }
};

