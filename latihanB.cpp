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

// Class Petugas untuk menangani peminjaman dan pengembalian
class Petugas {
private:
    string nama;
    int id;
    string levelAkses;

public:
    Petugas(string n, int i, string l) : nama(n), id(i), levelAkses(l) {}

    // Fungsi untuk memproses peminjaman buku
    void prosesPinjam(Buku* b, Peminjaman* p) {
        if (!b->dipinjam) {
            b->dipinjam = true;
            p->tambahBuku(1); // Tambah jumlah buku yang dipinjam
            cout << "Buku '" << b->judul << "' telah dipinjam oleh " << p->getNama() << endl;
        } else {
            cout << "Buku '" << b->judul << "' sudah dipinjam." << endl;
        }
    }

    // Fungsi untuk memproses pengembalian buku
    void prosesKembali(Buku* b, Peminjaman* p) {
        if (b->dipinjam) {
            b->dipinjam = false;
            p->tambahBuku(-1); // Kurangi jumlah buku yang dipinjam
            cout << "Buku '" << b->judul << "' telah dikembalikan oleh " << p->getNama() << endl;
        } else {
            cout << "Buku '" << b->judul << "' belum dipinjam." << endl;
        }
    }

    // Friend class Admin agar bisa mengakses data petugas
    friend class Admin;
};

// Class Admin untuk mengelola petugas dan melihat status peminjaman
class Admin {
private:
    string nama;
    int id;

public:
    Admin(string n, int i) : nama(n), id(i) {}

    // Fungsi untuk mengubah level akses petugas
    void ubahLevelAkses(Petugas* p, string level) {
        p->levelAkses = level;
        cout << "Level akses petugas " << p->nama << " telah diubah menjadi " << level << endl;
    }

    // Fungsi untuk melihat jumlah buku yang dipinjam oleh peminjam
    void lihatJumlahBuku(Peminjaman* p) {
        cout << "Jumlah buku yang dipinjam oleh " << p->getNama() << ": " << p->getJumlahBuku() << endl;
    }

    // Fungsi untuk melihat total pinjaman
    void lihatTotalPinjaman(Peminjaman* p) {
        cout << "Total pinjaman oleh " << p->getNama() << ": " << p->getTotalPinjaman() << endl;
    }

    // Fungsi untuk melihat buku yang sedang diproses
    void lihatBukuSedangDiproses(Buku* b) {
        if (b->dipinjam) {
            cout << "Buku '" << b->judul << "' sedang dipinjam." << endl;
        } else {
            cout << "Buku '" << b->judul << "' belum dipinjam." << endl;
        }
    }

    // Friend class Petugas agar bisa melihat dan mengubah data petugas
    friend class Petugas;
};

