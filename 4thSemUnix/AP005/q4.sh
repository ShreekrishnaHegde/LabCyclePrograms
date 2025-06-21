#SS to copy multiple files into the directory
#!/bin/bash
echo -e "Enter the directory name: \c"
read dir
if [ ! -d $dir ];then
	echo "Directory not found"
	exit 1
fi
args=("$@") #Storing all args in arrays	
for((i=0 ; i<$# ;i++))
do
	fileName="${args[i]}"
	if [ -f $fileName ];then
		cp "$fileName" "$dir"
		echo "Copied $fileName to $dir"
	else
		echo "File $fileName not found"
	fi
done
