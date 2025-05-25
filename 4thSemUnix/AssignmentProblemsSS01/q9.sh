#Write a shell script to display the file permissions for the given file
#!/bin/bash
echo -e "Enter the name of the file: \c"
read fileName
if [ ! -e $fileName ]
then
	echo "File doesn't exists"
	exit 1
fi
echo "Permission of $fileName :"
ls -l $fileName | cut -d ' ' -f 1
