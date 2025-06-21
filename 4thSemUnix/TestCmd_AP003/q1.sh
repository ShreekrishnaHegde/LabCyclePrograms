#Write a shell script that takes the filename and checks whether file exists or not
#!/bin/bash
echo -e "Enter the filename: \c"
read file
if test -e $file;then
	echo "File exists"
else
	echo "File doesn't exists"
fi
