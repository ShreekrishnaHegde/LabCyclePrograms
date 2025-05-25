#Write a shell script to perform basic arithmatic operations using case
#!/bin/bash
ch=1
while [ ch != 6 ]
do	
	echo "1.Addition 2.Subtraction 3.Multiplicaion 4. Division 5.Modulous 6.Exit"
	echo -e "Enter your choice: \c"
	read ch
	if [ $ch -eq 6 ];then 
		echo "Exiting"
		exit 0
	fi
	echo -e "Enter two numbers: \c"
        read a b
	case $ch in 
		1)
			echo "$a + $b = `expr $a + $b`";;
		2)
			echo "$a - $b = `expr $a - $b`";;
		3) 
			echo "$a x $b = `expr $a \* $b`";;
		4)	
			if [ $b -ne 0 ];then
				echo "$a / $b = `expr $a / $b`"
			else
				echo "Cannot divide by zero"
			fi
			;;
		5)
			if [ $b -ne 0 ];then
				echo "$a % $b = `expr $a % $b`"
			else
				echo "Cannot divide by zero"
			fi
			;;
		*)
			echo "Invalid choice";;
	esac
done
