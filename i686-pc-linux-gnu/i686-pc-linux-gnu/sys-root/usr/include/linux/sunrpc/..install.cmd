cmd_/synosrc2/GPLSource/evansport-build/source/linux-3.x/usr/include/linux/sunrpc/.install := perl scripts/headers_install.pl /synosrc2/GPLSource/evansport-build/source/linux-3.x/include/linux/sunrpc /synosrc2/GPLSource/evansport-build/source/linux-3.x/usr/include/linux/sunrpc x86 debug.h; perl scripts/headers_install.pl /synosrc2/GPLSource/evansport-build/source/linux-3.x/include/linux/sunrpc /synosrc2/GPLSource/evansport-build/source/linux-3.x/usr/include/linux/sunrpc x86 ; for F in ; do echo "\#include <asm-generic/$$F>" > /synosrc2/GPLSource/evansport-build/source/linux-3.x/usr/include/linux/sunrpc/$$F; done; touch /synosrc2/GPLSource/evansport-build/source/linux-3.x/usr/include/linux/sunrpc/.install
