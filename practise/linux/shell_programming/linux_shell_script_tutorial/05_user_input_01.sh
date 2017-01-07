#!/bin/bash
<<comment_code
echo "<<<<<< Multiple Input >>>>>>"
read -p "Prompt Enter Data:: " variable1 variable2 variableN    
# 1st two arguments are assigned to variable1 and variable2, then remaining will be assigned to variableN
echo "variable1:: ${variable1}"
echo "variable2:: ${variable2}"
echo "variableN:: ${variableN}"
printf "\r------------------\n"
echo ""
echo "<<<<<< Timeout Input >>>>>>"
read -t 3 -p "Prompt Enter Data:: " variable1 variable2 variableN
echo "variable1:: ${variable1}"
echo "variable2:: ${variable2}"
echo "variableN:: ${variableN}"
printf "\r------------------\n"

echo "<<<<<< Handling Passwords >>>>>>"
read -s -p "Enter Password : " my_password
echo
echo "Your password - $my_password"
printf "\r------------------\n"

echo "<<<<<< \$IFS and read command together >>>>>>"
VarCombined="string1 string2 string3 string4"
# printf "%s" $VarCombined
echo $VarCombined
read -r varName1 varName2 varName3 <<< "$VarCombined"
echo ""
echo "varName1:: ${varName1}"
echo "varName2:: ${varName2}"
echo "varName3:: ${varName3}"
echo "------------------"
read -r varName11 varName21 <<< "${VarCombined}"
echo "varName11:: ${varName11}"
echo "varName21:: ${varName21}"
printf "\r------------------\n"
comment_code

echo "<<<<<< change the IFS separator value >>>>>>"
VarCombined="gitevivek:x:1002:1002::/home/gitevivek:/bin/sh"
# Save the Internal Field Separator to a variable called old
old="$IFS"
# Set the Internal Field Separator to a colon (i.e. change the Internal Field Separator)
IFS=:
# Read $VarCombined and generate tokens using $IFS and store them into respective fields
read -r login password uid gid info home shell <<< "$VarCombined"
printf "Your login name is %s, uid %d, gid %d, home dir set to %s with %s as login shell\n" $login $uid $gid $home $shell
# Finally, restore the Internal Field Separator value using $old
IFS="$old"
printf "\r------------------\n"
#======================================