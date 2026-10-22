import random

print("================================")
print("Selamat datang di permainan tebak angka!")
print("Silahkan memilih tingkat kesulitan:")
print("1. Mudah (1-20)")
print("2. Sedang (1-50)")
print("3. Sulit (1-100)")
print("================================")

try:
    level = int(input("Masukkan pilihan tingkat kesulitan (1-3): "))
except ValueError:
    print("Input tidak valid, mengatur ke level Mudah (1-20).")
    level = 1

if level == 1:
    max_number = 20
elif level == 2:
    max_number = 50
elif level == 3:
    max_number = 100
else:
    print("Pilihan tidak valid, mengatur ke level Mudah (1-20).")
    max_number = 20

# PERBAIKAN: Angka yang benar harus dibuat sekali saja di luar loop
angka_benar = random.randint(1, max_number)
max_tebakan = 10
jumlah_tebakan = 0

print(f"\nKamu memiliki maksimal {max_tebakan} kali kesempatan.")

while jumlah_tebakan < max_tebakan:
    try:
        user_number = int(input(f"\nKesempatan ke-{jumlah_tebakan + 1}. Masukkan angka tebakanmu (1-{max_number}): "))
    except ValueError:
        print("Mohon masukkan angka yang valid.")
        continue # Lewati sisa loop dan minta input lagi tanpa mengurangi kesempatan (atau bisa dikurangi jika mau)
    
    jumlah_tebakan += 1

    if user_number == angka_benar:
        print(f"Selamat! Tebakanmu benar dalam {jumlah_tebakan} kali percobaan.")
        break
    elif user_number < angka_benar:
        print("Tebakanmu terlalu kecil. Coba lagi.")
    else:
        print("Tebakanmu terlalu besar. Coba lagi.")

if user_number != angka_benar:
    print(f"\nSayang sekali, kamu sudah menebak {max_tebakan} kali. Angka yang benar adalah {angka_benar}.")