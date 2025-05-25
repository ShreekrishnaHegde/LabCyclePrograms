#Write a shellscript to print the first 10 natural numbers
#!/bin/bash
echo -e "Enter a number: \c"
read n
for((i=1;i<=n;i++))
do
	echo "$i"
done
