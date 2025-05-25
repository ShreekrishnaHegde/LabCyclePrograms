#To check if given string is palindrome or not 
#!/bin/bash

echo -e "Enter a string: \c"
read str
reverse=""
len=${#str}

for (( i=$len-1;i>=0;i-- ))
do
  reverse=$reverse${str:$i:1}
done
if [[ $reverse == $str ]]
then
	echo "The String $str is a palindrome"
else
	echo "The String $str is not a palindrome"
fi

# # is used to get the length of the string
#$ {var:stratigindex:length}
