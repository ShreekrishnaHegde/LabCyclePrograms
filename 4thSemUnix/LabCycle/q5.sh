#Write a shell script to read a file name and pattern as variables and search the pattern 
#in given file. Display suitable messages if wrong entries are made. 

#!/bin/bash
echo -e "Enter the filename: \c"
read file

if [ ! -f $file ];then
	echo "File does not exist"
 	exit 1
fi
echo -e "Enter the pattern to be searched: \c"
read pat
if [ -z $pat ];then
	echo "Pattern cannot be empty"
	exit 1
fi

grep "$pat" $file

if [ $? -eq 0 ];then
echo "Command executed successfully"
else
	echo "Command failed"
fi


