#!/bin/bash

<<<<<<< HEAD
#wget http://www.image-net.org/challenges/LSVRC/2012/nnoupb/ILSVRC2012_bbox_val_v3.tgz
#other downloads: http://www.image-net.org/challenges/LSVRC/2012/nonpub-downloads
#read: https://pjreddie.com/darknet/imagenet/

=======
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
mkdir -p labelled
wd=`pwd`

for f in val/*.xml;
do
label=`grep -m1 "<name>" $f | grep -oP '<name>\K[^<]*'`
im=`echo $f | sed 's/val/imgs/; s/xml/JPEG/'`
out=`echo $im | sed 's/JPEG/'${label}'.JPEG/; s/imgs/labelled/'`
ln -s ${wd}/$im ${wd}/$out
done

find ${wd}/labelled -name \*.JPEG > inet.val.list

