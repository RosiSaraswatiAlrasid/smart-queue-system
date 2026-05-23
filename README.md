# Smart Queue System Berbasis IoT

Proyek ini merupakan sistem antrean pintar berbasis Internet of Things (IoT) menggunakan ESP32, LCD I2C, Firebase Realtime Database, buzzer, push button, dan LED indikator.

Sistem ini dirancang untuk membantu proses antrean administrasi agar lebih teratur, otomatis, dan realtime.

---

## Fitur Sistem

- Pengambilan nomor antrean otomatis
- Pemanggilan antrean menggunakan tombol admin
- Tampilan nomor antrean pada LCD 16x2
- Monitoring realtime menggunakan Firebase
- Notifikasi suara menggunakan buzzer
- Indikator LED status pelayanan

---

## Komponen yang Digunakan

- ESP32
- LCD I2C 16x2
- Push Button
- LED Merah
- LED Hijau
- Resistor 220Ω
- Buzzer
- Firebase Realtime Database

---

## Fungsi Tombol

### Tombol Hijau (Mahasiswa/User)
Digunakan untuk mengambil nomor antrean secara otomatis.

Ketika tombol ditekan:
- Nomor antrean bertambah
- Sistem menyimpan antrean terbaru
- LCD menampilkan total antrean

---

### Tombol Kuning (Admin)
Digunakan untuk memanggil nomor antrean berikutnya.

Ketika tombol ditekan:
- Nomor antrean dipanggil
- LCD menampilkan nomor yang dipanggil
- Buzzer berbunyi
- Data dikirim ke Firebase secara realtime

---

## Fungsi LED

### LED Hijau
Menandakan bahwa nomor antrean dipersilakan menuju meja administrasi.

### LED Merah
Menandakan bahwa proses pelayanan sedang berlangsung.

---

## Cara Kerja Sistem

1. Mahasiswa menekan tombol hijau untuk mengambil nomor antrean
2. Nomor antrean tersimpan pada sistem
3. Admin menekan tombol kuning untuk memanggil antrean
4. LCD menampilkan nomor yang dipanggil
5. Buzzer berbunyi sebagai notifikasi
6. Status antrean dikirim ke Firebase secara realtime

---

## Teknologi yang Digunakan

- Arduino IDE
- ESP32
- Firebase Realtime Database
- Wokwi Simulator

---

## Link Project

### Wokwi Simulation
(Tambahkan link Wokwi di sini)

### GitHub Repository
(Tambahkan link GitHub di sini)

---

## Author

Rosi Saraswati Alrasid
