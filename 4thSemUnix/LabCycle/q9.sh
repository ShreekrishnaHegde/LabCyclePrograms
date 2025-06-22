#Write a shell program to accept a designation code and its description from terminal and 
#perform validation and then add an entry to file desig.lst. The designation code should 
#be numeric only and designation description should be alphabetical only. 
#!/bin/bash
file="desig.lst"
while true;
do
	echo -e "Enter designation code(numerical): \c"
	read code
	case $code in
		""|*[!0-9]*) echo "Error: Code must be numeric only"
		   	     continue
			     ;;
	esac
	echo -e "Enter designation description(alphabetical): \c"
	read desc
	case $desc in 
		""|*[!a-zA-Z]*) echo "Error: Description must be alphabetical only"
			     	continue
			     	;;
	esac
	echo "$code - $desc">>"$file"
	echo "Entry added succesfully"
	echo -e "Do you want to add another entry? (y/n) : \c"
	read ch
	if [ "$ch" != "y" ];then
		echo "Contents of $file are: "
		cat "$file"
		break
	fi
done
