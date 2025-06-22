#Write a shell script to calculate and display the DA, HRA and gross salary of all the 
#employees in empn.lst. Assume Da 25% for those having salary > INR 6000 and 30% for 
#others. HRA is 10% of basic. 
#!/bin/bash
file="empn.lst"
if [ ! -f $file ];then
	echo "Error: empn.lst not found"
	exit 1;
fi
echo "----------------Employee Salary Details---------------"
cat $file | while read name sal
do
	#Calculating DA
	if [ $sal -gt 6000 ];then
		da=$(( sal*25/100 ))
	else
		da=$(( sal*30/100 ))
	fi
	#Calculating HRA
	hra=$(( sal*10/100 ))

	#calculating Gross Salary
	gross=$(( sal+da+hra ))

	echo "Emplyee Name: $name"
	echo "Emplyee BA: $sal"
	echo "Employee DA: $da"
	echo "Employee HRA: $hra"
	echo -e "Gross Salary: $gross\n"
done

