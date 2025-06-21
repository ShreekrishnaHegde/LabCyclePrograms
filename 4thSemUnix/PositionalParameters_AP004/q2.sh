#Write a SS to accept 1st name , last name and print "Hello firstname lastname"
#!/bin/bash
if [ ! $# -eq 2 ];then
	echo "Invalid number of Args"
	exit 1
fi
echo "Hello $1 $2"
