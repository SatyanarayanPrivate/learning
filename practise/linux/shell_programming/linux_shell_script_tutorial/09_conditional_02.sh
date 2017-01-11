#!/bin/bash

echo ">>>>>>>>> Numeric comparison <<<<<<<<<<" 
varInt1=10
varInt2=12
varInt3=13
if [ $varInt1 -eq $varInt1 ]
then 
    echo "$varInt1 -eq $varInt1"
fi
if [ $varInt1 -ne $varInt2 ]
then 
    echo "$varInt1 -ne $varInt2"
fi
if [ $varInt3 -ge $varInt2 ]
then 
    echo "$varInt3 -ge $varInt2"
fi
if [ $varInt3 -gt $varInt2 ]
then 
    echo "$varInt3 -gt $varInt2"
fi
if [ $varInt1 -le $varInt2 ]
then 
    echo "$varInt1 -le $varInt2"
fi
if [ $varInt1 -lt $varInt2 ]
then 
    echo "$varInt1 -lt $varInt2"
fi
echo "============================"
echo ""


echo ">>>>>>>>> String comparison <<<<<<<<<<" 
read -p "Enter your String1:: " str1
read -p "Enter your String2:: " str2
if [ "$str1" = "$str2" ] 
then 
    echo '"$str1" = "$str2"'
fi
if [ $str1 = $str2 ] 
then 
    echo '$str1 = $str2' 
fi
if [ $str1 = "$str2" ]  # if $str2 is null gives error
then 
    echo '$str1 = "$str2"' 
fi
if [ "$str1" != "$str2""str" ] 
then 
    echo '"$str1" != "$str2"'
fi
read -p "Press Enter String1:: " str1
if [ -z $str1 ] 
then 
    echo '-z $str1'
fi
echo "============================"
echo ""

