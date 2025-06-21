#SS to demonstrate shoft commands
#!/bin/bash
echo "Before shift"
echo "AllArgs: $@"
echo "First Arg: $1"
echo "Last Arg: ${!#}"

shift

echo -e "\nAfter shift"
echo "AllArgs: $@"
echo "First Arg: $1"  
echo "Last Arg: ${!#}"

shift 2

echo -e "\nAfter shift 2"
echo "AllArgs: $@"
echo "First Arg: $1"
echo "Last Arg: ${!#}"
