#/bin/sh
. ./config.sh

rm -rf gcc463_glibc213_i686_evansport-GPL.tgz i686-pc-linux-gnu

wget http://heanet.dl.sourceforge.net/project/dsgpl/DSM%205.0%20Beta%20Tool%20Chains/Intel%20x86%20Linux%203.2.40%20%28Evansport%29/gcc463_glibc213_i686_evansport-GPL.tgz
tar zxpf gcc463_glibc213_i686_evansport-GPL.tgz

#Create Pharo Image
cd ${PHAROCROSSROOT}/pharo-vm/image/
sh newImage.sh
cd ${PHAROCROSSROOT}



