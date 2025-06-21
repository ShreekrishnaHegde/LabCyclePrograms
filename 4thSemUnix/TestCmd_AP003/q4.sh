#Write a SS to check if string is empty or not,to compare two strings,check if filename ends with .sh
#!/bin/bash
echo -e "Enter the strings: \c"
read str1 str2
if test -z $str1; then
	echo "String is empty"
else
	echo "String is not empty"
fi
if test "$str1" == "$str2";then 
	echo "Strings are same"
else
	echo "Strings are not same"
fi

echo -e "Enter the filename: \c"
read file
if test ! -e $file;then
	echo "File doesnt exists"
	exit 1
fi
