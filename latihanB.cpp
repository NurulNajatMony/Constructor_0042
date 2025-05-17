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

