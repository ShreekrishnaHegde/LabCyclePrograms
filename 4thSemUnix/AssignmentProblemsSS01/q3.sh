#Write a shell script to check whether give file is readable, writable and executable.
#!/bin/bash
echo -e "Enter the name of the file: \c"
read fileName
if [ ! -e $fileName ]
then
	echo "File doesn't exists"
	exit 1
fi

if [ -r $fileName ]
then
	echo "File is readble"
else
	echo "File is not readable"
fi
if [ -w $fileName ]
then
	echo "File is writable"
else
	echo"File is not writable"
fi
if [ -x $fileName ]
then
	echo "File is executable"
else
	echo "File is not executable"
fi
