#Write a shell script to know the size of individual files, permissions, existence of link and 
#file name. Display only these file attributes. 
#!/bin/bash
echo "Enter the file name"
read file
ls -l $file | cut -d ' ' -f 5,1,2,9
