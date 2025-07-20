#Write a shell script to implement an arithmetic calculator.
#!/bin/bash
echo "1.Addition 2.Subtraction 3.Multiplication 4.Division 5.Modulus"
echo -e "Enter your choice: \c"
read ch
echo -e "Enter the values(a and b) : \c"
read a b
case $ch in
	1)
		echo "$a + $b = `expr $a + $b` ";;
	2) 
		echo "$a - $b = `expr $a - $b` " ;;
	3) 
		echo "$a x $b = `expr $a \* $b` " ;;
	4) 
		if [ $b -eq 0 ];then
			echo "Denominator cannot be zero"
		else
			echo "$a / $b = `expr $a / $b`"
		fi
		;;
	5)
		if [ $b -eq 0 ];then
			echo "Denominator cannot be zero"
		else
			echo "$a % $b = `expr $a % $b`"
		fi
		;;

	*)echo "Invalid Choice";;
esac

