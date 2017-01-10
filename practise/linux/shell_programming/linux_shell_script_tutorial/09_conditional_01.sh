#!/bin/bash

echo ">>>>>>>>> if condition <<<<<<<<<<" 
varInt=10
if test $varInt == 10
then 
    echo "if condition int1 is true"
fi
if test $varInt == "10"
then 
    echo "if condition int2 is true"
fi
if test "$varInt" == 10
then 
    echo "if condition int3 is true"
fi
if test "$varInt" == "10"
then 
    echo "if condition int4 is true"
fi
if test $varInt == '10'
then 
    echo "if condition int5 is true"
fi
if test '$varInt' == '10'   # $varInt consider to be string instead of varInt value
then 
    echo "if condition int6 is true"
fi
echo "----------------------------"
varStr="str"
if test $varStr == "str"
then 
    echo "if condition str1 is true"
fi
if test $varStr == str
then 
    echo "if condition str2 is true"
fi
if test "$varStr" == str
then 
    echo "if condition str3 is true"
fi
if test $varStr == 'str'
then 
    echo "if condition str4 is true"
fi
if test '$varStr' == 'str'  # $varStr consider to be string instead of varStr value
then 
    echo "if condition str5 is true"
fi
echo "============================"

varInt1=10
if [ $varInt1 == 10 ]
then 
    echo "if condition int11 is true"
fi
if [ "$varInt1" == "10" ]
then 
    echo "if condition int12 is true"
fi
if [ '$varInt1' == '10' ]   # $varInt consider to be string instead of varInt value
then 
    echo "if condition int13 is true"
fi
echo "----------------------------"
varStr1="str"
if [ $varStr1 == str ]
then 
    echo "if condition str11 is true"
fi
if [ "$varStr1" == "str" ]
then 
    echo "if condition str12 is true"
fi
if [ '$varInt1' == 'str' ]   # $varStr consider to be string instead of varStr value
then 
    echo "if condition str13 is true"
fi
echo "============================"

varInt2=11
varStr2="11"
if [ $varInt2 == $varStr2 ]
then 
    echo "if condition IntStr21 is true"
fi
echo "----------------------------"
if [ '$varInt2' == '$varStr2' ]
then 
    echo "if condition IntStr22 is true"
fi
echo "----------------------------"
if [ $varInt2 -eq $varStr2 ]
then 
    echo "if condition IntStr23 is true"
fi
echo "----------------------------"
# if [ '$varInt2' -eq '$varStr2' ]    # $varInt2: integer expression expected
# then 
#     echo "if condition IntStr24 is true"
# fi
if [ "$varInt2" -eq "$varStr2" ]
then 
    echo "if condition IntStr25 is true"
fi
echo "----------------------------"
echo "============================"


echo ""
echo ">>>>>>>>> if then else condition <<<<<<<<<<" 
varInt3=11
varStr3="11"
if [ $varInt3 -eq $varStr3 ]
then 
    echo "if else condition IntStr31 is true"
else
    echo "if else condition IntStr31 is false"
fi
echo "============================"

echo ""
echo ">>>>>>>>> multilevel if then else condition <<<<<<<<<<" 
varInt4=12
varStr4="2"
if [ $varInt4 -gt $varStr4 ]
then 
    echo "multilevel if else condition IntStr41 is true"
elif [ $varInt4 -lt $varStr4 ]
then
    echo "multilevel if else condition IntStr42 is true"
else 
    echo "multilevel if else condition IntStr43 is true"
fi
echo "============================"






