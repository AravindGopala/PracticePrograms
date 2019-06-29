#! /bin/sh
# Usage hl758
stringZ=20000000000.100.23.324
#       =======	    
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



echo "Rasing interface $Intf $IPAddr $DNS1"

echo `expr match "$stringZ" '\([0-9]*\).'`   # abcABC1
