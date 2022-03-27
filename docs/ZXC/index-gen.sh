#!/bin/bash

cat "$1" > "$1".indexed

>index

i=(-1 1)
prevLen=0
while read -r line; do
    hash="$(md5sum <<< "$line" | cut -d ' ' -f 1)"
    printf "<a id=\"%s\"></a>\n%s\n" "$hash" "$line" > tmp
    sed "/$line/ {
        x
        r /home/xewii/Documents/TIT/ZXC/tmp
    }" "$1".indexed > "$1".indexed.tmp
    mv "$1".indexed.tmp "$1".indexed
    hdrLen=$(awk -F'#' '{print NF-1}' <<< "$line")
    hdrTxt=$(echo "${line//#/}")
    (( $hdrLen > 1 )) && for (( j=1; j<$hdrLen*4; j++ )); do printf ' '; done
    (( $prevLen < $hdrLen )) && i[$hdrLen]=1
    printf "%d. [%s ](#%s)\n" ${i[$hdrLen]} "$hdrTxt" "$hash"
    prevLen=$hdrLen
    let i[$hdrLen]++
done <<< "$(grep --color=no -E "^#+ " "$1")" > index

mv "$1".indexed tmp
printf "# Содержание\n" > "$1".indexed
cat index >> "$1".indexed
cat tmp >> "$1".indexed

# rm tmp
# rm index
