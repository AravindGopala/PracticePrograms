#! /bin/sh
# Usage hl7588_connect.sh <intf> <IP_Address> <DNS1>
#
# Example: 
#  Connect to wwan1 using IP = 10.22.33.44
# > sudo hl7588_connect.sh -i wwan1 -a 10.22.33.44 -d 8.8.8.8 
	
# Set defualts before parsing

BroadAddr="10.255.255.255"

# Parse input argruments
while getopts ":i:d:a:" opt; do
  case $opt in
    i)
      Intf=$OPTARG
      ;;
    a)
      IPAddr=$OPTARG
      ;;
    d)
      DNS1=$OPTARG
      ;;
    \?)
      echo "Invalid option: -$OPTARG" >&2
      ;;
  esac
done

echo "Rasing interface $Intf $IPAddr $DNS1"

First_Octet=$(expr match "$IPAddr" '\([0-9]*\).')

if [ $First_Octet == "10" ]; then
  BroadAddr="10.255.255.255"
  echo "Strings are equal $BroadAddr"

elif [ $First_Octet == "172" ]; then
  BroadAddr="172.31.255.255"
  echo "Strings are equal $BroadAddr"

elif [ $First_Octet == "192" ]; then
  BroadAddr="192.168.255.255"
  echo "Strings are equal $BroadAddr"
fi


exit 0