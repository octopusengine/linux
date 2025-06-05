| [Directory struct](https://github.com/octopusengine/linux/blob/master/directory_struct.md) | [Disk](https://github.com/octopusengine/linux/blob/master/disk.md) | [Network](https://github.com/octopusengine/linux/blob/master/network.md) | [Multimedia](https://github.com/octopusengine/linux/blob/master/multimedia.md) | [App & Prog](https://github.com/octopusengine/linux/blob/master/app_prg.md) | **Code_cypher** | [Links](https://github.com/octopusengine/linux/blob/master/links.md) |

---

## Code | Cypher | Hash | ...

### Simple Involution

Negation
```bash
# negation of a binary string
echo "11100010" | tr '10' '01'
# 00011101
```

Reverse
```bash
# Reverse a string
echo "agamapoint" | rev
tniopamaga
```

ROT13 | Caesar (13)
```bash
$ echo "Ntnzn cbvag frperg" | tr 'A-Za-z' 'N-ZA-Mn-za-m'
# Agama point secret
```

---

### Code

BASE64
```bash
# Encode a text string
echo -n "Agama point" | base64
# Output: QWdhbWEgcG9pbnQ=

# Encode the content of a file
base64 input.txt
# Output will be the Base64 encoded content of input.txt

# Encode and save to a file
echo -n "Hello, World!" | base64 > encoded.txt
# The encoded text will be stored in encoded.txt
```

---

### Hash

sha256
```bash
echo -n „AgamaPoint“ | sha256sum
# 29b5a9c21f25fcc7c015fee5...1e2f7
 
$ echo -n "agama3" | sha256sum | tr -d "[:space:]-" # correct hash

$ echo i=0; while ! (echo -n "Agama Point $i" | sha256sum | tr -d "\n"; echo " (nonce=$i)")|grep -E "^00"; do let i++; done
# 00999ac48b71fc267.....269d62d4b9f55b90b1  - (nonce=263)

$ echo i=0; while ! (echo -n "Agama Point $i" | sha256sum | tr -d "\n"; echo " (nonce=$i)")|grep -E "^000"; do let i++; done
# 00059e3f5b79199b149f1...b5c180b9a6616b9e  - (nonce=3439)
```

---

```bash
hexdump -C FILE
tr                     (translate or delete characters)
$ echo test | tr -d"t" >> es
```

dec2bin
```bash
echo "obase=2; 42" | bc

printf "%b\n" "$(echo "obase=2; 42" | bc)"

echo | awk '{ printf("%08d\n", strtonum("42") + 0) }'
```

dec2hex
```bash
echo "obase=16; 42" | bc
# 101010

printf "%X\n" 42

echo | awk '{ printf("%X\n", 42) }'

echo 42 | xargs printf "%X\n"

echo "obase=16; 42" | bc | tr '[:upper:]' '[:lower:]'
```

MASK
```bash
# Using bc to mask with 0xFFFFFFFF
echo "obase=16; 42 & FFFFFFFF" | bc
# 
```

```bash
#!/bin/bash

# Function to normalize a number to 32-bit hexadecimal
normalize_to_32bit() {
    local num=$1
    local masked_num=$(( num & 0xFFFFFFFF ))
    printf "%08X\n" $masked_num
}

# Example usage
normalize_to_32bit 42  # 0000002A
normalize_to_32bit 255 # 000000FF
normalize_to_32bit 4294967295  # Should output FFFFFFFF
normalize_to_32bit 4294967296  # Should output 00000000 (overflow case)
```

XOR
```bash
# Hexadecimal numbers
hex1="1A2B3C4D"
hex2="9F8E7D6C"

# Perform XOR operation
result=$(echo "obase=16; ibase=16; $hex1 ^ $hex2" | bc)
echo $result

---

# Hexadecimal numbers
hex1="1A2B3C4D"
hex2="9F8E7D6C"

# Convert hex to decimal, perform XOR, and convert back to hex
dec1=$((16#$hex1))
dec2=$((16#$hex2))
xor_result=$((dec1 ^ dec2))
printf "%X\n" $xor_result
# 85A54121

# Hexadecimal numbers
hex1="1A2B3C4D"
hex2="9F8E7D6C"

 Perform XOR operation using awk
echo | awk -v hex1=$hex1 -v hex2=$hex2 'BEGIN {
    dec1 = strtonum("0x" hex1)
    dec2 = strtonum("0x" hex2)
    xor_result = dec1 ^ dec2
    printf "%X\n", xor_result
}'
```

entropy
```bash
hexdump -C -n 256 /dev/random

# ->
00000000  64 52 9f 9b d6 a7 c0 ef  82 fd 73 a2 ca 1f b4 c9  |dR........s.....|
00000010  2d 52 04 c8 5d df b9 f0  e0 7b 43 71 bd d5 d4 9e  |-R..]....{Cq....|
00000020  23 3b 39 34 7d b0 b1 b2  f7 76 0e 75 19 7d 14 02  |#;94}....v.u.}..|
00000030  dc 6b e1 a2 5c 62 29 98  e4 d7 84 bb d8 d7 54 e6  |.k..\b).......T.|
00000040  97 0b 9a 10 ca ca f4 0a  d5 f2 76 4d a3 8b ce c6  |..........vM....|
00000050  2f 72 93 4b 5a c8 fc 56  da 5c 6a 18 6d 7a 6a 5d  |/r.KZ..V.\j.mzj]|
00000060  72 32 84 b2 1c bb eb 0d  18 1d ad f8 1f 49 7d 9d  |r2...........I}.|
00000070  30 2c 0f 63 fb 79 32 c2  59 70 4c d2 fe f6 10 7c  |0,.c.y2.YpL....||
00000080  6c b9 dd 3d cd ca 58 05  4a b9 b2 5b 3c 8c a8 35  |l..=..X.J..[<..5|
00000090  55 98 f5 55 31 73 34 52  00 8d 31 d6 02 4e cc 12  |U..U1s4R..1..N..|
000000a0  0c 34 6b b9 1e ac 90 52  f5 5c ec 6b 71 13 dd 31  |.4k....R.\.kq..1|
000000b0  86 fe 9d 0e 6a 9a 6e 21  ba 34 b6 6d 54 1f 82 be  |....j.n!.4.mT...|
000000c0  91 3f 69 54 45 98 df f9  a8 4e a7 53 cb 64 a1 13  |.?iTE....N.S.d..|
000000d0  c5 23 06 87 8d 31 4b 9d  23 28 d9 f9 a3 1c 4b d7  |.#...1K.#(....K.|
000000e0  80 59 98 3d c0 94 d6 20  bf 65 f8 92 3c fc 01 26  |.Y.=... .e..<..&|
000000f0  5d 2c 2d 90 00 bc 2a d2  58 c8 cd 76 fc 5e ac 76  |],-...*.X..v.^.v|
```

---

gpg
```bash
sudo apt install gnupg
gpg -c secret_file.txt
gpg -d secret_file.txt.gpg > tajny_soubor.txt


tar czf tajna_slozka.tar.gz tajna_slozka/
gpg -c tajna_slozka.tar.gz

gpg -d tajna_slozka.tar.gz.gpg > tajna_slozka.tar.gz
tar xzf tajna_slozka.tar.gz

linux:
# https://www.gnupg.org/
win:
# https://www.gpg4win.org/
```







