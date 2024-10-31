# FLOPRO : Flood Prevention and River Observation

![Logo FLOPRO](https://github.com/RaihanKP10/FLOPRO-Flood-Prevention-and-River-Observation/blob/main/Assets/logo%20watersafe.jpg)

## Hardware Desain

![Desain Hardware](https://github.com/RaihanKP10/FLOPRO-Flood-Prevention-and-River-Observation/blob/main/Hardware/Blok%20Diagram%20v1.png)

Konsep kerja dari alat ini adalah mengukur ketinggian air melalui sensor ultrasonik HCSR-04, kemudian hasil pengukuran dikirim ke server untuk ditampilkan melalui aplikasi. Ketika ketinggian air mendekati permukaan, sistem memberikan informasi berupa suara dan memicu terbukanya pintu air menggunakan motor servo yang terhubung ke bendungan. 

Pengiriman data sensor ke server membutuhkan koneksi internet, dan karena alat ini ditempatkan di luar ruangan, diperlukan modem WiFi sebagai sumber data internet eksternal. Selain itu, alat ini memanfaatkan energi matahari sebagai sumber listrik dengan menggunakan panel surya mini, yang energinya kemudian disimpan dalam baterai.
