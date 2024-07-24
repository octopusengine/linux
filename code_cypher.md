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

# Perform XOR operation using awk
echo | awk -v hex1=$hex1 -v hex2=$hex2 'BEGIN {
    dec1 = strtonum("0x" hex1)
    dec2 = strtonum("0x" hex2)
    xor_result = dec1 ^ dec2
    printf "%X\n", xor_result
}'
```







