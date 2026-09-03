#include <iostream>

const int MAX_N = 10000;

void printEliminationProcess(int N, int K) {
    // Array untuk menandai status eliminasi astronot
    // active[i] = true jika astronot ke-(i+1) masih berada di dalam lingkaran
    bool active[MAX_N];
    for (int i = 0; i < N; i++) {
        active[i] = true;
    }

    int remaining = N;
    int currentIndex = 0; // Memulai perhitungan dari astronot nomor 1 (index 0)

    std::cout << "--- Proses Eliminasi Astronot ---" << std::endl;

    while (remaining > 1) {
        // Hitung sebanyak K astronot yang masih aktif
        int count = 0;
        while (count < K) {
            if (active[currentIndex]) {
                count++;
            }
            if (count < K) {
                currentIndex = (currentIndex + 1) % N;
            }
        }

        // Astronot pada currentIndex dieliminasi
        active[currentIndex] = false;
        int eliminatedNumber = currentIndex + 1; // Nomor astronot (1-based index)
        remaining--;

        std::cout << "Astronot " << eliminatedNumber << " dieliminasi. ";

        // Aturan perubahan nilai K berdasarkan nomor astronot yang dieliminasi
        if (eliminatedNumber % 2 == 0) {
            K += 2; // Jika genap, K bertambah 2
        } else {
            K -= 1; // Jika ganjil, K berkurang 1
        }

        // Nilai K tidak boleh kurang dari 2
        if (K < 2) {
            K = 2;
        }

        std::cout << "Nilai K baru: " << K << std::endl;

        // Cari posisi astronot aktif berikutnya untuk memulai hitungan berikutnya
        if (remaining > 1) {
            do {
                currentIndex = (currentIndex + 1) % N;
            } while (!active[currentIndex]);
        }
    }

    // Cari astronot terakhir yang masih bertahan
    int lastAstronaut = -1;
    for (int i = 0; i < N; i++) {
        if (active[i]) {
            lastAstronaut = i + 1;
            break;
        }
    }

    std::cout << "\n=================================" << std::endl;
    std::cout << "Astronot terakhir yang bertahan: Astronot #" << lastAstronaut << std::endl;
    std::cout << "=================================" << std::endl;
}

int main() {
    int N, K;

    std::cout << "Masukkan jumlah astronot (N): ";
    if (!(std::cin >> N)) {
        std::cout << "Input tidak valid! Masukkan angka." << std::endl;
        return 1;
    }

    std::cout << "Masukkan nilai awal K: ";
    if (!(std::cin >> K)) {
        std::cout << "Input tidak valid! Masukkan angka." << std::endl;
        return 1;
    }

    if (N <= 0 || K < 2) {
        std::cout << "Input tidak valid! N harus > 0; <10000 dan K harus >= 2." << std::endl;
        return 1;
    }

    if (N > MAX_N) {
        std::cout << "N terlalu besar untuk versi ini (maks " << MAX_N << ")." << std::endl;
        return 1;
    }

    printEliminationProcess(N, K);

    return 0;
}