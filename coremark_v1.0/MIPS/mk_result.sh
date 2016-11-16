grep total_usec log_coremark_$1.txt | sed -r -e "s/total_usec : +//g"> result_coremark_$1.txt

