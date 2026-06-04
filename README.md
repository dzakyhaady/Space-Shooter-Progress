# Space Shooter (Progress)

Space Shooter adalah game sederhana berbasis C++ dan SFML. Game ini menggunakan konsep horizontal shooter: pemain mengendalikan pesawat di sisi kiri layar, menembak obstacle yang datang dari sisi kanan, dan berusaha bertahan selama mungkin sambil mengumpulkan score. Ini adalah repository progress dna untuk finalisasi project akan ada repository terpisah.

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

## Asset yang Digunakan

Game menggunakan asset dari folder `assets`, antara lain:

- `bgcc.png` untuk background.
- `ship5.gif` untuk pesawat player.
- `batu.gif` untuk obstacle.
- `backsound.wav` untuk musik latar.


## Status Project

Game sudah dapat dijalankan dan di-debug melalui Visual Studio Code. Struktur kode juga sudah dipisah menjadi beberapa class agar lebih mudah dikembangkan, misalnya untuk menambah health, level, jenis musuh, animasi, sound effect, atau menu utama. **Repository ini hanyalah untuk progress saja, untuk finalisasi game akan ada repository terpisah**.
