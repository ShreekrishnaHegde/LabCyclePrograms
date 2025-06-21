#Write a SS to accept a filename and checck whether it is regular file or directory.
#!/bin/bash
echo -e "Enter the filename: \c"
read file
if test ! -e $file;then
	echo "File doesn't exists"
	exit 1
fi
if test -f $file;then 
	echo "File is Regular"
elif test -d $file;then
	echo "Directory"
fi
