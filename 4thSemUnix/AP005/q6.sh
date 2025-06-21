#SS to demonstrate bubble sort 
#!/bin/bash
nums=("$@")
echo "Array Before Sorting: "
for item in ${nums[@]}
do
	echo -e "$item \c"
done
n=$#
for((i=0; i<n-1 ; i++))
do
	for((j=0; j<n-i-1; j++))
	do
		if [ ${nums[$j]} -gt ${nums[$j+1]} ];then
			temp=${nums[$((j))]}
			nums[$j]=${nums[$((j+1))]}
			nums[$((j+1))]=$temp
		fi
	done
done
echo -e "\nArray After Sorting: "
for item in ${nums[@]}
do
        echo -e "$item \c"
done
echo 
