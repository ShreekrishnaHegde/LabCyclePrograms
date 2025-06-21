#Write a SS to accept two arguments and print thier sum
#!/bin/bash
if [ $# -ne 2 ];then
	echo "Pass exaclty 1 Args"
	exit 1
fi
sum=$(($1 + $2))
echo "$1 + $2 = $sum" 
