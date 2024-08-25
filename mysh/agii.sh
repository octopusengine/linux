#!/bin/bash

# --- simple Agama image infilt. | ver. 0.2 / 2024/08 ---
#$ chmod +x agii.sh
#$ ./agg.sh image.png

workdir="data21" # Relative working directory

# Check if the directory exists; if not, create it
if [ ! -d "$workdir" ]; then
  echo "Creating directory $workdir..."
  mkdir "$workdir"
fi

img="$1" # Get the argument passed to the script

# Check if the argument was provided
if [ -z "$img" ]; then
  echo "No image file provided. Usage: ./agg.sh image.png"
  exit 1
fi

# Construct the path to the image file
img_path="$workdir/$img"

# Check if the image file exists
if [ ! -f "$img_path" ]; then
  echo "Image file $img does not exist in $workdir."

  # Create the image file using the Python script if it does not exist
  echo "Creating image file $img in $workdir..."
  python agamage.py crea "$img_path" 128x96

  # Verify that the file was successfully created
  if [ ! -f "$img_path" ]; then
    echo "Failed to create image file $img in $workdir."
    exit 1
  fi
fi

echo "Processing img: $img_path" # Display the name of the image file


# Check if data21/hex.txt exists and choose the correct input for the second Python script
hex_file_path="$workdir/hex.txt"

if [ -f "$hex_file_path" ]; then
  # If hex.txt exists, use it as input
  python agamage.py ibin "$img_path" "$hex_file_path" -x 0 -y 0 -c R
else
  # If hex.txt does not exist, use the string "abc123" as input
  echo "File hex.txt not found in $workdir. Using string 'abc123' instead."
  echo "abc123" | python agamage.py ibin "$img_path" /dev/stdin -x 0 -y 0 -c R
fi

python agamage.py info "$img_path" # Run Python script with the provided arguments
sha256_output=$(sha256sum "$img_path") # Calculate SHA-256 hash of the image file
echo " .:..:.  $sha256_output" # Display SHA-256 hash with a prefix

echo "--- fin.ok ---"

# test:
# ./agii.sh image1.png
# python agamage.py pbin data21/image1.png -x 0 -y 0 -l 128 -c R
# ABC12300000000000000000000000000
# python agamage.py ibin data21/image1.png data21/test1.txt -x 0 -y 0 -c G
# python agamage.py pbin data21/image1.png -x 0 -y 0 -l 128 -c G

# img defa 317 Bytes, 128*96=12288, /8=1536, /2=768 chars
# SHA 8b3486b289c50a6e4a0b6ba09662d9636bc7d3c664d3cc50d0085e3abb794739
# hexdump -C -n 256 data21/image1.png