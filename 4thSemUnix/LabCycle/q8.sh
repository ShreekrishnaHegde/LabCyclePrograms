#Write an interactive code to accept a list of items and item code and append the item 
#code and item name in a file named item.txt.
#!/bin/bash

file="item.txt"
while true;
do
	echo -e "Enter the Item Name: \c"
	read name
	echo -e "Enter the Item Code: \c"
	read code
	echo -e "$code - $name">>"$file"
	echo "Item added to the $file"

	echo "Do you want to add another item? (y/n)"
	read ch
	if [ "$ch" != "y" ];then
		echo "Appended all the items to $file.Contents of $file are: "
	      	cat "$file"
		break
	fi
done	

