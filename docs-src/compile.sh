#!/bin/bash

input="cursed.md"
pdfHeaderInput="header.pdf"
indexedMdOut="../docs/cursed.md"
htmlOut="../docs/index.html"
pdfOut="../docs/cursed.pdf"
pdfHederedOut="../docs/cursedHeadered.pdf"
umlDir="uml"
imgDirOut="../docs/img"

function indexGen() {
    out="${1/.md/}".indexed.md

    cp "$1" "$out"

    > index

    tab='\t'
    i=(-1 1)
    prevLen=0
    while read -r line; do
        hash="$(md5sum <<< "$line" | cut -d ' ' -f 1)"
        printf "<a id=\"%s\"/>\n\n%s\n\n" "$hash" "$line" > tmp
        sed "/$line/ {
            x
            r tmp
        }" "$out" > "${out}.tmp"
        mv "${out}.tmp" "$out"
        hdrLen=$(awk -F'#' '{print NF-1}' <<< "$line")
        hdrTxt="${line//#/}"
        (( hdrLen > 1 )) && for (( j=1; j<hdrLen; j++ )); do echo -en "$tab"; done
        (( prevLen < hdrLen )) && i[$hdrLen]=1
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

    mv "$out" "$2"
}

function umlGen() {
    plantuml uml/*
    mv uml/*.png "$1"/
}

function htmlGen() {
    pandoc -f markdown -s "$1" -o "$2"
}

function pdfGen() {
    echo not implemented
}

case $1 in
    prepare)
        [[ -d "$imgDirOut" ]] || mkdir -p "$imgDirOut"
        umlGen "$imgDirOut"
        ;;
    md)
        indexGen "$input" "$indexedMdOut"
        ;;
    html)
        htmlGen "$input" "$htmlOut"
        ;;
    pdf)
        pdfGen
        ;;
    *)
        ;;
esac
