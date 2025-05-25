#To calculate the factorial of a number
#!/bin/bash
result=1
echo -e "Enter a number: \c"
read n
if [ $n -eq 0 ]
then
	echo "Factorial of $n is 0"
else
	for((i=1;i<=n;i++))
	do
        	result=$((result*i))
	done
	echo "Factorial of $n is $result"
fi

