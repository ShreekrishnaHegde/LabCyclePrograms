#Write a shell script to perform arithmatic operations using bc command
#!/bin/bash
echo -e "Enter two numbers: \c"
read a b
echo "$a + $b = $( echo "$a + $b" | bc )"
echo "$a - $b = $( echo "$a - $b" | bc )"
echo "$a x $b = $( echo "$a * $b" | bc )"
isZero=$(echo "$b == 0" | bc)
if [ "$isZero" -eq 0 ]
then
        echo "$a / $b = $(echo "$a / $b" | bc)"
else
        echo "Denominator cannot be zero for division"
fi
