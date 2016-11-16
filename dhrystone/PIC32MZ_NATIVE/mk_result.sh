grep total_time log_dhrystone_$1.txt | sed -r -e "s/usec//g;s/\#\#\#\# total_time = +//g" > result_dhrystone_$1.txt

