#!/bin/bash

# ((expression))
echo "<<<<<< basic operations >>>>>>"
varName1=10
varName2=20
varAns=$((varName1+varName2))
echo "$varName1 + $varName2 = $varAns"
printf "\r------------------\n\n"
#===============================

varName11=10
varName21=20.5  # will give an error
varAns1=$((varName11+varName21))
echo "$varName11 + $varName21 = $varAns1"
printf "\r------------------\n\n"
#===============================