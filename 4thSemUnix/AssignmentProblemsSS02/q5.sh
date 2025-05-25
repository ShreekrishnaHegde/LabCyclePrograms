#To print the multiplication table of a number 
#!/bin/bash
echo -e "Enter a number: \c"
read n
for((i=1;i<=10;i++))
do
	echo "$n x $i = $((n*i))"
done
