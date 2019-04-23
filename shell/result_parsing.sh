#!/bin/sh

if [ ! -f numbers.txt ] || [ ! -f sorted.txt ] || [ ! -f result.txt ];
then
	exit 1
fi

grep [0-9] numbers.txt > check.txt
diff numbers.txt check.txt

if [ "$?" = "0" ];
then
	echo OK
else
	echo Fail
fi

exit 0
