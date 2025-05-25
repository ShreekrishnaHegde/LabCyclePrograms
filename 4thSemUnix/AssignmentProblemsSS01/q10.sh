#Write a shell script to take a file name and check whether it is regular file or directory
#!/bin/bash
echo -e "Enter the name of the file/directory: \c"
read fileName
if [ ! -e $fileName ]
then
	echo "File does not exists"
	exit 1
fi
if [ -f $fileName ]
then
	echo "Given file is a regular file"
elif [ -d $fileName ]
then
	echo "Given file is a directory"
else
	echo "Given file is neither a regular file nor a directory"
fi
