# FLOPRO : Flood Prevention and River Observation

![Logo FLOPRO](https://github.com/RaihanKP10/FLOPRO-Flood-Prevention-and-River-Observation/blob/main/Assets/logo%20watersafe.jpg)

## Penanggulangan Bencana Banjir dengan Monitoring Real-time Ketinggian Air Sungai Berbasis IoT

Proyek ini adalah Sistem Pemantauan Ketinggian Air Sungai yang menggunakan teknologi IoT untuk memberikan peringatan banjir secara real-time dengan mengukur ketinggian air sungai. Sistem ini dirancang untuk membantu manajemen bencana banjir dengan memberikan notifikasi kepada pemerintah daerah dan masyarakat tentang peningkatan ketinggian air, sehingga tindakan pencegahan dapat dilakukan sebelum banjir terjadi.

## Fitur
- **Pemantauan Real-Time**: Mengukur ketinggian air sungai secara terus-menerus menggunakan sensor.
- **Transmisi Data**: Mengirimkan data ke server cloud melalui perangkat IoT.
- **Sistem Peringatan Banjir**: Memberikan peringatan ketika ketinggian air melebihi ambang batas.
- **Antarmuka Web dan Mobile**: Menampilkan data dan peringatan pada dasbor yang mudah digunakan.
- **Penyimpanan Data**: Menyimpan data untuk analisis dan prediksi.
- **Pengaturan Ambang Batas**: Menyesuaikan ambang batas sesuai tingkat risiko.

## Anggota Tim

![FotoTim](https://github.com/RaihanKP10/FLOPRO-Flood-Prevention-and-River-Observation/blob/main/Assets/foto%20tim%201.jpeg)
![FotoTim1](https://github.com/RaihanKP10/FLOPRO-Flood-Prevention-and-River-Observation/blob/main/Assets/foto%20tim%202.jpeg)
![FotoTim1](https://github.com/RaihanKP10/FLOPRO-Flood-Prevention-and-River-Observation/blob/main/Assets/foto%20tim%203.jpeg)

| Foto                                                                                                          | NRP       | Nama                  | Jobdesk             | Akun                             |
|---------------------------------------------------------------------------------------------------------------|-----------|-----------------------|---------------------|----------------------------------|
| ![Foto Ody](https://github.com/RaihanKP10/FLOPRO-Flood-Prevention-and-River-Observation/blob/main/Assets/Screenshot%202024-10-28%20101007.png) | 2122600036 | Dafit Ody Endriantono | UI/UX Designer     | [Ody](https://github.com/DafitOdy-In) |
| ![Foto Thofail](https://github.com/RaihanKP10/FLOPRO-Flood-Prevention-and-River-Observation/blob/main/Assets/Screenshot%202024-10-28%20101120.png) | 2122600037 | Thofail Syakirudin    | Hardware           | [Thofail](https://github.com/DzavanTS) |
| ![Foto Rif'at](https://github.com/RaihanKP10/FLOPRO-Flood-Prevention-and-River-Observation/blob/main/Assets/Screenshot%202024-10-28%20101217.png) | 2122600046 | Ahmad Miftahur Rif'at | Mechanical         | [Rif'at](https://github.com/AatForUX) |
| ![Foto Zanuar](https://github.com/RaihanKP10/FLOPRO-Flood-Prevention-and-River-Observation/blob/main/Assets/Screenshot%202024-10-28%20101243.png) | 2122600051 | Zanuar Dwi Novaliyanto | Mechanical         | [Zanuar](https://github.com/ZanuarDwiNovaliyanto) |
| ![Foto Raihan](https://github.com/RaihanKP10/FLOPRO-Flood-Prevention-and-River-Observation/blob/main/Assets/Screenshot%202024-10-28%20101315.png) | 2122600056 | Moch Raihan Kemal P   | Software           | [Raihan](https://github.com/RaihanKP10) |
| ![Foto Asyraf](https://github.com/RaihanKP10/FLOPRO-Flood-Prevention-and-River-Observation/blob/main/Assets/Screenshot%202024-10-28%20101343.png) | 2122600060 | Asyraf Sulthan Zaky   | Project Manager    | [Asyraf](https://github.com/AsyrafSinclair) |

## Hardware Desain
![Desain Hardware](https://github.com/RaihanKP10/FLOPRO-Flood-Prevention-and-River-Observation/blob/main/Hardware/Blok%20Diagram%20v1.png)

Alat ini mengukur ketinggian air dengan sensor ultrasonik HCSR-04 dan mengirimkan data ke server untuk ditampilkan melalui aplikasi. Ketika ketinggian mendekati ambang batas, sistem memicu servo untuk membuka pintu air di bendungan. Karena alat berada di luar ruangan, data dikirim melalui modem WiFi, dan energi diperoleh dari panel surya mini yang disimpan dalam baterai.

---

##Demonstrasi Kalibrasi Sensor
1. Link Demonstrasi Kalibrasi Sensor HCSR04 :

   
![Kalibrasi HC-SR04_FLOPRO_Proyek IOT   Jaringan Sensor](https://github.com/user-attachments/assets/8981be6d-f395-4317-9425-955d1f3de2b1)
   
   https://youtube.com/shorts/4SDvYGCIjRk?feature=share
   
   "Kalibrasi sensor HC-SR04 adalah proses penyesuaian sensor ultrasonik ini untuk meningkatkan akurasi dalam mengukur jarak. Sensor HC-SR04 bekerja dengan mengirimkan gelombang ultrasonik dari pemancar (transmitter) dan menghitung waktu yang dibutuhkan oleh gelombang tersebut untuk memantul kembali ke penerima (receiver) setelah mengenai suatu objek. Dengan menggunakan kecepatan suara sebagai acuan, sensor ini dapat menghitung jarak objek berdasarkan waktu tempuh gelombang."

3. Link Demonstrasi Kalibrasi Servo MG90s :
   
   https://youtube.com/shorts/B2ZGl9izdCo?feature=share
   
   "Kalibrasi servo MG90S adalah proses penyetelan servo motor ini untuk memastikan bahwa sudut putarannya akurat sesuai dengan sinyal kontrol yang diterima. Servo MG90S adalah servo motor kecil yang banyak digunakan dalam proyek robotika dan sistem kontrol, dengan kemampuan untuk berputar pada sudut tertentu berdasarkan sinyal PWM (Pulse Width Modulation) yang diterimanya."

4. Link Demonstrasi Kalibrasi Mini Speaker :
   
   https://youtu.be/lZPbhcjN7L0
   
   "Kalibrasi mini speaker adalah proses penyesuaian output suara dari speaker kecil untuk mencapai kualitas audio yang optimal sesuai kebutuhan. Mini speaker sering digunakan dalam perangkat elektronik portabel dan sistem suara kecil. Kalibrasi pada mini speaker bertujuan untuk memastikan bahwa suara yang dihasilkan sesuai dengan frekuensi yang diinginkan, volume yang tepat, serta tanpa distorsi."

&copy; 2024 FLOPRO. All rights reserved.
