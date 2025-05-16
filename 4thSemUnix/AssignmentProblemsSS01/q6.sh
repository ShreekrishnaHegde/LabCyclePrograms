#to print largest of three numbers

#!/bin/bash
echo -e "Enter three numbers: \c"
read a b c
if [[ $a -gt $b && $a -gt $c ]];
then
	echo "$a is the largest"
elif [[ $b -gt $a && $b -gt $c ]];
then
	echo "$b is the largest"
elif [[ $c -gt $a && $c -gt $b ]];
then
	echo "$c is the largest"
else
	echo "Enter unique numbers"
fi
