#!/bin/bash

echo ">>>>>>>>> File attributes comparisons <<<<<<<<<<" 
if [ -e /etc/profile ]
then 
    echo '-e /etc/profile'
fi
if [ -a /etc/profile ]
then 
    echo '-a /etc/profile'
fi
if [ -f /etc/profile ]
then 
    echo '-f /etc/profile'
fi
if [ -c /etc/profile ]
then 
    echo '-c /etc/profile'
else    
    echo 'false -c /etc/profile #############'
fi
if [ -b /dev/loop0 ]
then 
    echo '-b /dev/loop0'
fi
if [ -d /dev ]
then 
    echo '-d /dev'
fi
echo "============================"
echo ""

