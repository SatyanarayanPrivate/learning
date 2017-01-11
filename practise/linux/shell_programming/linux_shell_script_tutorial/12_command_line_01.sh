#!/bin/bash
echo '>>>>>>>>> command line arguments <<<<<<<<<<'
echo "Command line argument 0:: $0"
echo "Command line argument 1:: $1"
echo "Command line argument 2:: $2"
echo "Command line argument 3:: $3"
echo "Number of Command line arguments:: $#"
echo "Command line argument as \$@:: $@"
echo "Command line arguments as \$*:::: $*"
echo "============================"
echo ""

echo '>>>>>>>>> difference between $@ and $* <<<<<<<<<<'
OLDIFS=$IFS
echo 'Displaying all arguments names using $@'
echo "$@"
echo
echo 'Displaying all arguments names using \$* with default $IFS'
echo "$*"
IFS=", "
echo 'Displaying all arguments names using \$* with IFS=", "'
echo "$*"
IFS=$OLDIFS
echo "============================"
echo ""
