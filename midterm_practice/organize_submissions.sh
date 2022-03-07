#!/bin/sh
##Emma Claire Kinnison
##3/7/21
##comments:This is my shell script the midterm

if  [ ! -d  "out_directory/" ]
then
    mkdir "out_directory"
fi


tar -xvzf filename.tar.gz
