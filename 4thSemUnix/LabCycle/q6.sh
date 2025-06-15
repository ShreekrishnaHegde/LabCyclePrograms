#Write an interactive shell script using variables to check the existence of a particular user 
#login account. Display suitable messages if wrong entries are made.
#!/bin/bash
echo -e "Enter the username: \c"
read user
if [[ -z $user ]];then
	echo "Username cannt be empty"
	exit 1
fi
if who | cut -d ' ' -f 1 | grep -wq "^$user$";then
	echo "user exixts"
else
	echo "user doesnot exists"
fi
