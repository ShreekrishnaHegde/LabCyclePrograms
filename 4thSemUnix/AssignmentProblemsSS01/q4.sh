#Write a shell script to read a filename from use and display its content.
#!/bin/bash
echo -e "Enter the name of the file: \c"
read fileName
if [ ! -e $fileName ]
then
	echo "File doesn't exists"
	exit 1
fi
echo "Contents of file $fileName :"
cat $fileName

