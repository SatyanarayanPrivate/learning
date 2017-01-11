#!/bin/bash

echo ">>>>>>>>> case statement <<<<<<<<<<" 

read -p "enter string:: " readdata
case $readdata in
    mon)
        echo "Full backup1";;
    Mon)
        echo "Full backup"
        ;;
    Tue|Wed|Thu|Fri)
        echo "Partial backup";;
    Sat|Sun)
        echo "No backup";;
    *) ;;
esac
echo "============================"
echo ""

echo "############### Dealing with case sensitive pattern ###############" 
echo ">>>>>>>>> Solution#1:: Convert pattern to lowercase/uppercase <<<<<<<<<<" 
read -p "enter string:: " readdata
opt=$( tr '[:upper:]' '[:lower:]' <<<"$readdata" )
echo "lowercase:: ${opt}"
case $opt in
    sql)
        echo "sql selected" ;;
    tar)
        echo "tar selected" ;;
    *) 
        ;;
esac
echo "----------------------------"
opt=$( tr '[:lower:]' '[:upper:]' <<<"$readdata" )
echo "uppercase::  ${opt}"
echo "============================"
echo ""

echo ">>>>>>>>> Solution#2:: Use regex with case patterns <<<<<<<<<<" 
read -p "enter string:: " readdata
opt=$( tr '[:upper:]' '[:lower:]' <<<"$readdata" )
echo "${opt}"
case $opt in
    [Ss][Qq][Ll])
        echo "sql selected" ;;
    [Tt][Aa][Rr])
        echo "tar selected" ;;
    *) 
        ;;
esac
echo "============================"
echo ""

echo ">>>>>>>>> Solution#3:: Turn on nocasematch <<<<<<<<<<" 
read -p "enter string:: " readdata
opt=$( tr '[:upper:]' '[:lower:]' <<<"$readdata" )
echo "${opt}"
shopt -s nocasematch    # Turn on a case-insensitive matching (-s set nocasematch)
case $opt in
    sql)
        echo "sql selected" ;;
    tar)
        echo "tar selected" ;;
    *) 
        ;;
esac
shopt -u nocasematch    # Turn off a case-insensitive matching (-u unset nocasematch)
echo "============================"
echo ""
