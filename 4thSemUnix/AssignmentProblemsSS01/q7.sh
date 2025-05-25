#Write a shell script to print whether given file exists or not
#!/bin/bash
echo -e "Enter the name of the file: \c"
read fileName
if [ -e $fileName ]
then
	echo "Given file exists"
else
	echo "Given file doesn't exists" 
fi
