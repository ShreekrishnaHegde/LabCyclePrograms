#SS using test and CLA with if-else statements
#!/bin/bash
echo -e "Enter the argument number: \c"
read arg
if test $arg -gt $#;then
	echo "Invalid Argument Number"
	exit 1
else
	args=("$@") #Array of all args
	index=$(($arg-1)) #Array is 0 indexed
	echo "Argument $arg is: ${args[$index]}"
fi



	
