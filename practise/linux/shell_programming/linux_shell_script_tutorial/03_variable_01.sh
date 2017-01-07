#!/bin/bash
varInt=10
varString="string_value"
varFloat=2.5
echo ""

echo "<<<<<< Variable Print >>>>>>"
echo "using echo"
echo "varInt:: ${varString}"
echo "varString:: $varString"
echo "varFloat:: $varFloat"
#======================================
printf "\r------------------\n"
printf "using printf\n"
printf "varInt:: %d\n" $varInt
printf "varString:: %s\n" ${varString}
printf "varFloat:: %f\n" $varFloat
printf "\r------------------\n"
printf "quoting difference\n"
echo "Path is $PATH" ## $PATH will be expanded
echo 'I want to print $PATH' ## PATH will not be expanded
printf "\r------------------\n"
#======================================
echo ""
echo "<<<<<< Variable assignment >>>>>>"
VarInt=10
VarFloat=12.2
VarFloat=${VarInt}
echo "VarInt:: ${VarInt}"
echo "VarFloat:: ${VarFloat}"
echo "VarString:: ${VarString=string assignment}"
echo "VarString1:: ${VarString1-string assignment1}" # as VarString is not set use default "string assignment1":
echo "VarString:: ${VarString}"   # updated string will be printed
echo "VarString1:: ${VarString1}"   # VarString1 is nullstring
echo ""
#======================================
echo "<<<<<< Syntax \":=\" >>>>>>"
echo ${arg:=Foo}
bank=HSBC
echo ${bank:=Citi}
unset bank
echo ${bank:=Citi}
printf "\r------------------\n"
VarInt=20
echo "VarInt:: ${VarInt:=30}"
echo "VarInt1:: ${VarInt1:=30}"
printf "\r------------------\n"
die(){
#     local error=${1:=Undefined error} # this will give an error.
    local error=${1:-Undefined error}
    echo "$0: $LINE $error"
}
# call die() with an argument
die "File not found"
# call die() without an argument
die
#======================================