#!/bin/bash
read -p "enter string:: " readdata
opt=$( tr '[:upper:]' '[:lower:]' <<<"$readdata" )
echo "${opt}"
echo ""
opt=$( tr '[:lower:]' '[:upper:]' <<<"$readdata" )
echo "${opt}"
echo ""