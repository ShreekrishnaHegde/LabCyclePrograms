#Write a SS to cehck if a given file is Readable,Writable,Executable or empty.
#!/bin/bash
echo -e "Enter the filname: \c"
read file
if test ! -e $file;then
	echo "File doesnt exists"
	exit 1
fi
if test -r $file;then
	echo "File is readable"
fi
if test -w $file;then
	echo "File is writable"
fi
if test -x $file;then
	echo "File is executable"
fi
if test ! -s $file;then
	echo "File is empty"
else
	echo "File is not empty"
fi
