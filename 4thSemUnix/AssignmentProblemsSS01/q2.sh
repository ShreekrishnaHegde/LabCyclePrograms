#Write a shellscript to check whether given number is +ve -ve or zero

#!/bin/bash
#-e is added to interpret escape sequences, add -e if echo doesn't interprets escape seqences by default.
echo -e "Enter a number: \c"
read n
if [ $n -gt 0 ]
then
	echo "$n is possitive"
elif [ $n -lt 0 ]
then
	echo "$n is negative"
else
	echo "$n is zero"
fi
