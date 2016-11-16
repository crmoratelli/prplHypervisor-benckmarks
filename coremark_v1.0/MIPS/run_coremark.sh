#!/bin/sh
if [ $# -eq 0 ] ; then
num_of_loop=10
LOG_FILE=log_coremark.txt
elif [ $# -eq 1 ] ; then
num_of_loop=$1
LOG_FILE=log_coremark.txt
else
num_of_loop=$1
LOG_FILE=$2
fi

echo "" > ${LOG_FILE}
for i in `seq 1 $num_of_loop`
do
echo \#\#\#\# loop:$i/$num_of_loop | tee -a ${LOG_FILE}
echo \#\#\#\# `date` | tee -a ${LOG_FILE}
 ./coremark 0x0    0x0    0x66 0 7 1 2000 | tee -a ${LOG_FILE}
echo \#\#\#\# `date` | tee -a ${LOG_FILE}
done


# echo performance run ...
#  ./coremark 0x0    0x0    0x66 0 7 1 2000 > run1.log
# echo validation  run ...
# ./coremark 0x3415 0x3415 0x66 0 7 1 2000 > run2.log

