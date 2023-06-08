| [Directory struct](https://github.com/octopusengine/linux/blob/master/directory_struct.md) | [Disk](https://github.com/octopusengine/linux/blob/master/disk.md) | [Network](https://github.com/octopusengine/linux/blob/master/network.md) | **Multimedia** | [App & Prog](https://github.com/octopusengine/linux/blob/master/app_prg.md) | [Links](https://github.com/octopusengine/linux/blob/master/links.md) |

---

## Multimedia

### Images

```bash
$ jp2a (convert jpg to ASCIIart)
$ jp2a IMAGE.jpg --output=IMG_ASCII.txt

magick FILE.jpg FILE.png  (Convert Between Image Formats)
$ magick rose.jpg -resize 50% rose.png
$ magick -size 320x85 canvas:none -font Bookman-DemiItalic -pointsize 72 \
  -draw "text 25,60 \'Magick\'" -channel RGBA -blur 0x6 -fill darkred -stroke magenta \
  -draw "text 20,55 \'Magick\'" fuzzy-magick.png
$ magick input.png -colorspace RGB +sigmoidal-contrast 11.6933 \
  -define filter:filter=Sinc -define filter:window=Jinc -define filter:lobes=3 \
  -resize 400% -sigmoidal-contrast 11.6933 -colorspace sRGB output.png');

```

gimp

inkscape

---

### Audio

audacity

lmms

cecilia

mixxx



---

### Video

vlc

VSDC video editor

```bash
$ sudo apt install ffmpeg
$ ffmpeg -i input.mp4 -vn -acodec libmp3lame -ab 192k output.mp3
```
---

### webcam
```bash
cheese

fswebcam -r "${CAM_RESOLUTION}" --info "${CAM_INFO_TEXT}" --font "${CAM_FONT}" --banner-colour "${CAM_BANNER_COLOUR}" --text-colour<br /> ${CAM_TEXT_COLOUR} --line-colour ${CAM_LINE_COLOUR} /tmp/temp.jpg
debug "Get picture from camera"
[ ! -e "/tmp/temp.jpg" ] && echo "Error while getting picture" >&2 && exit 1
debug "Uploading photo to server"

curl -s -X POST -F "fileToUpload=@/tmp/temp.jpg" -F "authkey=${UPLOAD_KEY}" -F "submit=1" ${UPLOAD_CURL_EXTRA_PARAMS} "${UPLOAD_URL}" > /dev/null
```
---
