#!/bin/bash
<<comment01
echo "<<<<<< integer variable >>>>>>"
declare -i varInt1=12
declare -i varInt2=13
declare -i ans=0
ans=$((varInt1 + varInt2))
    echo "$varInt1 + $varInt2 = $ans"
varInt1=string_sample
echo "varInt1:string: $varInt1"
varInt1=1.2 # gives error
echo "varInt1:float: $varInt1"
varInt1=20
echo "varInt1:int: $varInt1"
printf "\r------------------\n\n"
#===============================

echo "<<<<<< constants variable >>>>>>"
readonly varConst1
varConst1=12 # gives error
# readonly varConstStr="varConstStr"
declare -r varConstStr="varConstStr"
echo "varConstStr:: $varConstStr"
unset varConstStr # cannnot unset (delete) the readonly variable
echo "varConstStr:: $varConstStr"
printf "\r------------------\n\n"
#===============================
comment01

echo "<<<<<< Bash variable existence check >>>>>>"
varName1=string_sample
Verify=${varName1:?Error varable not defined}
echo "varName1 value is \"$Verify\""
unset varName1
Verify=${varName1:?"Error varName1 not defined"}
echo "varName1 value is \"$Verify\""
printf "\r------------------\n\n"
#===============================
