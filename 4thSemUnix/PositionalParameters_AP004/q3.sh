#Write a SS to accept two arguments and print thier sum
#!/bin/bash
if [ $# -ne 2 ];then
	echo "Error: Pass exaclty 2 Args"
	exit 1
else
	echo "Passed 2 Args"
fi

