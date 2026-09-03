#include <iostream>

// Fungsi manual untuk menghitung panjang string
int hitungPanjang(const char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Fungsi manual untuk memeriksa apakah karakter adalah huruf kapital
bool isUpper(char c) {
    return (c >= 'A' && c <= 'Z');
}

// Fungsi manual untuk memeriksa apakah karakter adalah huruf kecil
bool isLower(char c) {
    return (c >= 'a' && c <= 'z');
}

// Mengembalikan nilai alfabet (A/a=1, B/b=2, ..., Z/z=26)
int getNilaiAlfabet(char c) {
    if (isUpper(c)) {
        return c - 'A' + 1;
    } else if (isLower(c)) {
        return c - 'a' + 1;
    }
    return 0; // Karakter selain huruf tidak memberi nilai pergeseran
}

// Fungsi utama enkripsi Alien-In-The-Middle
void enkripsiAlien(const char input[], char output[]) {
    int n = hitungPanjang(input);
    if (n == 0) {
        output[0] = '\0';
        return;
    }

    // Karakter pertama tidak mengalami perubahan
    output[0] = input[0];

    // Proses pergeseran karakter ke-2 hingga selesai
    for (int i = 1; i < n; i++) {
        char curr = input[i];
        char prev = input[i - 1];

        int shift = getNilaiAlfabet(prev);

        if (isUpper(curr)) {
            output[i] = 'A' + (curr - 'A' + shift) % 26;
        } else if (isLower(curr)) {
            output[i] = 'a' + (curr - 'a' + shift) % 26;
        } else {
            output[i] = curr;
        }
    }
    output[n] = '\0'; // Menandai akhir string
}

int main() {
    char pesan[1000];
    char pesanTerenkripsi[1000];

    std::cout << "Masukkan pesan asli: ";
    std::cin.getline(pesan, 1000);

    enkripsiAlien(pesan, pesanTerenkripsi);

    std::cout << "Pesan sandi: " << pesanTerenkripsi << std::endl;

    return 0;
}