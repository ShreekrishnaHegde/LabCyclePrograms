#to perform basic arithmatic operations using case
#!/bin/bash
ch=1
while [ ch != 6 ]
do	
	echo "1.Addition 2.Subtraction 3.Multiplicaion 4. Division 5.Modulous"
	echo -e "Enter your choice: \c"
	read ch
	echo -e "Enter two numbers: \c"
        read a b
	case $ch in 
		1)
			echo "$a + $b = $((a+b))";;
		2)
			echo "$a - $b = $((a-b))";;
		3) 
			echo "$a x $b = $((a*b))";;
		4)
			echo "$a / $b = $((a/b))";;
		5)
			echo "$a % $b = $((a%b))";;
	esac
done
