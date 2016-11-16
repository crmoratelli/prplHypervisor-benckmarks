#!/bin/sh
if [ $# -eq 0 ] ; then
echo ログファイル名を指定してください。
exit -1
else
./run_dhrystone.sh 100 3000000 $1
fi

