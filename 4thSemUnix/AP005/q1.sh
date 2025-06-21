#SS to demonstrate CLA
#!/bin/bash
echo "Scropt name: $0"
echo "First Argumnet: $1"
echo "Last Argumnet: ${!#}"
echo "All Argumnet: $@"
echo "Number of Argumnet: $#"
