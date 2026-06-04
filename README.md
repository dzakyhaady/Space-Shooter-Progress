# Space Shooter

Space Shooter adalah game sederhana berbasis C++ dan SFML. Game ini menggunakan konsep horizontal shooter: pemain mengendalikan pesawat di sisi kiri layar, menembak obstacle yang datang dari sisi kanan, dan berusaha bertahan selama mungkin sambil mengumpulkan score.

## Fitur Game

- Gameplay horizontal shooter.
- Pesawat dapat bergerak ke 4 arah.
- Pesawat menembakkan peluru ke arah kanan.
- Obstacle muncul dari kanan dan bergerak ke kiri.
- Collision antara peluru dan obstacle akan menambah score.
- Collision antara pesawat dan obstacle akan memicu game over.
- Efek ledakan sederhana saat obstacle terkena peluru.
- Background dan backsound.
- Restart game setelah game over.
- Struktur kode dipisah menjadi beberapa class agar lebih mudah dipahami dan dikembangkan.

## Kontrol

| Tombol | Fungsi |
| --- | --- |
| Arrow Left | Gerak ke kiri |
| Arrow Right | Gerak ke kanan |
| Arrow Up | Gerak ke atas |
| Arrow Down | Gerak ke bawah |
| Space | Menembak |
| R | Restart setelah game over |

## Struktur Project

```text
SpaceShoot/
├── assets/
│   ├── bgcc.png
│   ├── ship5.gif
│   ├── batu.gif
│   └── backsound.wav
├── SFML-DLL/
│   └── file DLL SFML
├── .vscode/
│   ├── launch.json
│   └── tasks.json
├── SpaceShoott.cpp
├── Game.hpp
├── Game.cpp
├── Player.hpp
├── Player.cpp
├── Obstacle.hpp
├── Obstacle.cpp
├── Bullet.hpp
├── Bullet.cpp
├── Background.hpp
├── Background.cpp
├── Explosion.hpp
├── Explosion.cpp
├── Constants.hpp
└── README.md
```

## Penjelasan File

| File | Fungsi |
| --- | --- |
| `SpaceShoott.cpp` | Entry point program. Membuat object `Game` dan menjalankan game. |
| `Game.hpp` / `Game.cpp` | Mengatur game loop, event, update, render, collision, spawn obstacle, score, dan restart. |
| `Player.hpp` / `Player.cpp` | Mengatur pesawat player, movement 2 sumbu, batas layar, dan posisi awal peluru. |
| `Obstacle.hpp` / `Obstacle.cpp` | Mengatur obstacle/asteroid yang muncul dari kanan dan bergerak ke kiri. |
| `Bullet.hpp` / `Bullet.cpp` | Mengatur peluru yang ditembakkan player ke arah kanan. |
| `Background.hpp` / `Background.cpp` | Mengatur tampilan background game. |
| `Explosion.hpp` / `Explosion.cpp` | Mengatur efek ledakan sederhana. |
| `Constants.hpp` | Menyimpan konstanta seperti ukuran window, speed, dan delay spawn/tembak. |

## Dependency

Project ini menggunakan:

- C++17
- SFML 3
- MinGW g++
- Visual Studio Code dengan extension C/C++

Konfigurasi project saat ini memakai path:

```text
C:/SFML-3.0.2
C:/mingw64/bin/g++.exe
```

Jika lokasi SFML atau MinGW berbeda, ubah path tersebut di:

```text
.vscode/tasks.json
.vscode/launch.json
.vscode/c_cpp_properties.json
```

## Cara Build dan Run di VS Code

1. Buka folder project `SpaceShoot` di Visual Studio Code.
2. Pastikan SFML sudah tersedia di `C:/SFML-3.0.2`.
3. Pastikan MinGW tersedia di `C:/mingw64`.
4. Buka tab **Run and Debug**.
5. Pilih konfigurasi **Run SpaceShoot**.
6. Tekan `F5`.

VS Code akan menjalankan task build terlebih dahulu, lalu membuka game dalam mode debug.

## Cara Build Manual

Jika ingin build lewat terminal PowerShell:

```powershell
C:/mingw64/bin/g++.exe -std=c++17 -g `
  C:/SpaceShoot/SpaceShoott.cpp `
  C:/SpaceShoot/Game.cpp `
  C:/SpaceShoot/Background.cpp `
  C:/SpaceShoot/Player.cpp `
  C:/SpaceShoot/Bullet.cpp `
  C:/SpaceShoot/Obstacle.cpp `
  C:/SpaceShoot/Explosion.cpp `
  -IC:/SFML-3.0.2/include `
  -LC:/SFML-3.0.2/lib `
  -lsfml-graphics `
  -lsfml-window `
  -lsfml-system `
  -lsfml-audio `
  -o C:/SpaceShoot/SpaceShoott.exe
```

Sebelum menjalankan `.exe`, pastikan DLL SFML bisa ditemukan. Project ini menaruh DLL di folder `SFML-DLL`, dan `launch.json` sudah menambahkan folder tersebut ke `PATH` saat debug dari VS Code.

## Asset yang Digunakan

Game menggunakan asset dari folder `assets`, antara lain:

- `bgcc.png` untuk background.
- `ship5.gif` untuk pesawat player.
- `batu.gif` untuk obstacle.
- `backsound.wav` untuk musik latar.

Font akan dicari dari:

1. `assets/arial.ttf`
2. `C:/Windows/Fonts/arial.ttf`

Jika game dijalankan di komputer lain dan font tidak muncul, tambahkan file `arial.ttf` ke folder `assets`.

## Status Project

Game sudah dapat dijalankan dan di-debug melalui Visual Studio Code. Struktur kode juga sudah dipisah menjadi beberapa class agar lebih mudah dikembangkan, misalnya untuk menambah health, level, jenis musuh, animasi, sound effect, atau menu utama.
