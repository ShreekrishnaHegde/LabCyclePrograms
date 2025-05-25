#Write a shell script to perform arithmatic operations using expr and bc command
#!/bin/bash
echo -e "Enter two numbers: \c"
read a b
echo "$a + $b = `expr $a + $b`"
echo "$a - $b = `expr $a - $b`"
echo "$a x $b = `expr $a \* $b`"
if [ $b -ne 0 ];then
	echo "$a / $b = `expr $a / $b`"
	echo "$a % $b = `expr $a % $b`"
else
	echo "Denominator cannot be zero for division and modulus"
fi
