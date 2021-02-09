#!/bin/bash_shellshock

echo "Content-type: text/plain"
echo 
echo "*** ENVIRONMENT VARIABLES***"
strings /proc/$$/environ
