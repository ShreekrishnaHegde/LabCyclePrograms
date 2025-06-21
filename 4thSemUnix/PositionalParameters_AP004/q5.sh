#SS to accept 3 Args and print them in reverse order
#!/bin/bash
if [ $# -ne 3 ];then
	echo "Invalid number of Args"
	exit 1
fi
echo "3rd Argumnet: $3"
echo "2n Argument: $2"
echo "1st Argument: $1"
