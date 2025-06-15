#Design a menu to display different shell commands. Provide the user the choice to 
#execute different shell commands. 

#!/bin/bash
echo "1.who 2.whoami 3.date 4.ls -l 5.exit"
echo -e "Enter your choice: \c"
read ch
case $ch in
	1)who;;
	2)whoami;;
	3)date;;
	4)ls -l;;
	5)exit;;
	*)echo "Invalid Entry"
esac
