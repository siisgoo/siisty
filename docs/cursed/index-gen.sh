#!/bin/bash

out="${1/.md/}".indexed.md

cp "$1" "$out"

> index

i=(-1 1)
prevLen=0
while read -r line; do
    hash="$(md5sum <<< "$line" | cut -d ' ' -f 1)"
    printf "<a id=\"%s\"></a>\n%s\n" "$hash" "$line" > tmp
    sed "/$line/ {
        x
        r tmp
    }" "$out" > "${out}.tmp"
    mv "${out}.tmp" "$out"
    hdrLen=$(awk -F'#' '{print NF-1}' <<< "$line")
    hdrTxt=$(echo "${line//#/}")
    (( $hdrLen > 1 )) && for (( j=1; j<$hdrLen*4; j++ )); do printf ' '; done
    (( $prevLen < $hdrLen )) && i[$hdrLen]=1
    printf "%d. [%s ](#%s)\n" ${i[$hdrLen]} "$hdrTxt" "$hash"
    prevLen=$hdrLen
    let i[$hdrLen]++
done <<< "$(grep --color=no -E "^#+ " "$1")" > index

cat "$out" > "$out".tmp
printf "# Содержание\n" > "$out"
cat index >> "$out"
cat "$out".tmp >> "$out"

rm index
rm tmp
rm "$out".tmp
