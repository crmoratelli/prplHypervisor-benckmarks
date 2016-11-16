#!/bin/sh
if [ $# -eq 0 ] ; then
echo ログファイル名を指定してください。
exit -1
else
./run_coremark.sh 100 $1
fi

