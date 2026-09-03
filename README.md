##### Nama: Syifa Rizky Amelia

##### Kelompok: Vanadium

###### Repository ini berisi hasil pengerjaan tantangan Pemrograman Dasar TLS 2026, yang terdiri dari dua fase:

###### (1) Perancangan logika penyelesaian masalah dalam bentuk pseudocode/flowchart pada problem 1 dan 2;

&#x09;a) **Problem 1: The Last Astronaut**

&#x09;Disusun dalam bentuk **pseudocode**. Masalah ini merupakan variasi Josephus Problem dengan nilai K yang berubah setiap kali ada eliminasi (bertambah 2 jika nomor astronot 	yang dieliminasi genap, berkurang 1 jika ganjil, dengan batas bawah K = 2). Status hidup/mati tiap astronot disimpan dalam array boolean alive\[], dan pergerakan 	melingkar ke astronot hidup berikutnya ditangani oleh fungsi bantu NEXT\_ALIVE().



&#x09;b) **Problem 2: Alien-In-The-Middle**

&#x09;Disusun dalam bentuk **flowchart**. Setiap huruf pada pesan digeser berdasarkan nilai alfabet huruf tepat sebelumnya (huruf pertama tidak mengalami perubahan), dengan 	pergeseran mengikuti aritmatika modulo 26 agar melingkar kembali ke A setelah melewati Z.



###### (2) Implementasi solusi problem 1 dan 2 tersebut dalam bahasa C++.

&#x09;a) The Last Astronaut

&#x09;Input: jumlah astronot N dan nilai awal K.

&#x09;Output: urutan astronot yang dieliminasi beserta nilai K yang diperbarui setiap putaran, dan astronot terakhir yang bertahan.

&#x09;Batasan: N maksimal 10.000 (ukuran array active\[] bersifat statis, ditentukan lewat konstanta MAX\_N).



&#x09;b) Alien-In-The-Middle

&#x09;Input: pesan asli (string, maksimal 999 karakter).

&#x09;Output: pesan yang telah disandikan sesuai sistem sandi.

&#x09;Fungsi manual yang dibuat: hitungPanjang(), isUpper(), isLower(), getNilaiAlfabet(), enkripsiAlien().

