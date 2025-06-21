#SS to demonstrate string using test command
#!/bin/bash
echo -e "Enter two strings: \c"
read str1 str2
if test -z $str1 || test -z $str2;then
	echo "String(s) are empty"
	exit 1
fi
if test "$str1" == "$str2";then
	echo "Strings are equal"
else
	echo "Strings are not equal"
fi
