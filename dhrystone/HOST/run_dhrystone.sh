#!/bin/sh
if [ $# -eq 0 ] ; then
num_of_loop=10
loop_param=100000000
elif [ $# -eq 1 ] ; then
num_of_loop=$1
loop_param=100000000
LOG_FILE=log_dhrystone.txt
elif [ $# -eq 1 ] ; then
num_of_loop=$1
loop_param=$2
LOG_FILE=log_dhrystone.txt
else
num_of_loop=$1
loop_param=$2
LOG_FILE=$3
fi

echo "" > ${LOG_FILE}
for i in `seq 1 $num_of_loop`
do
echo \#\#\#\# loop:$i/$num_of_loop | tee -a ${LOG_FILE}
echo \#\#\#\# `date` | tee -a ${LOG_FILE}
./gcc_dry2 << EOF | tee -a ${LOG_FILE}
$loop_param
EOF
echo \#\#\#\# `date` | tee -a ${LOG_FILE}
done

