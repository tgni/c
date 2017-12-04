#!/bin/bash
DIR=out
OUTPUT=output
FILES=`ls $DIR` 

cd $DIR
mkdir $OUTPUT -p
for i in ${FILES}
do
	echo "/* File: $i */" > tmp
	cat $i >> tmp
	cp tmp $OUTPUT/$i
done
rm tmp

cd $OUTPUT
FILES=`ls`
for i in ${FILES}
do
	cat $i >> origin.src 
done
cd ../..
exit
