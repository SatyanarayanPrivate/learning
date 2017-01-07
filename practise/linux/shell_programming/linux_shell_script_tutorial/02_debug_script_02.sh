#!/bin/bash
### Turn on debug mode ###
set -x
echo "Debug mode enabled"
echo "Today is $(date)"
echo "############################################"
echo ""

### Turn off debug mode ###
set +x
echo "Debug mode disabled"
echo "Today is $(date)"
echo "############################################"
echo ""

set -n # only read command but do not execute them
echo "Debug mode only read"
echo "Today is $(date)"
echo "############################################"
echo ""

set -o noexec
echo "Debug mode noexec"
echo "Today is $(date)"
echo "This is a test"
echo "############################################"
echo ""
# no file is created as bash will only read commands but do not

