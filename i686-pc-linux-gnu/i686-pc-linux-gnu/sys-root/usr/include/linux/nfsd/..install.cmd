cmd_/synosrc2/GPLSource/evansport-build/source/linux-3.x/usr/include/linux/nfsd/.install := perl scripts/headers_install.pl /synosrc2/GPLSource/evansport-build/source/linux-3.x/include/linux/nfsd /synosrc2/GPLSource/evansport-build/source/linux-3.x/usr/include/linux/nfsd x86 debug.h export.h nfsfh.h stats.h; perl scripts/headers_install.pl /synosrc2/GPLSource/evansport-build/source/linux-3.x/include/linux/nfsd /synosrc2/GPLSource/evansport-build/source/linux-3.x/usr/include/linux/nfsd x86 ; for F in ; do echo "\#include <asm-generic/$$F>" > /synosrc2/GPLSource/evansport-build/source/linux-3.x/usr/include/linux/nfsd/$$F; done; touch /synosrc2/GPLSource/evansport-build/source/linux-3.x/usr/include/linux/nfsd/.install
