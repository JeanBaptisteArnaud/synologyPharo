cmd_/synosrc2/GPLSource/evansport-build/source/linux-3.x/usr/include/scsi/fc/.install := perl scripts/headers_install.pl /synosrc2/GPLSource/evansport-build/source/linux-3.x/include/scsi/fc /synosrc2/GPLSource/evansport-build/source/linux-3.x/usr/include/scsi/fc x86 fc_els.h fc_fs.h fc_gs.h fc_ns.h; perl scripts/headers_install.pl /synosrc2/GPLSource/evansport-build/source/linux-3.x/include/scsi/fc /synosrc2/GPLSource/evansport-build/source/linux-3.x/usr/include/scsi/fc x86 ; for F in ; do echo "\#include <asm-generic/$$F>" > /synosrc2/GPLSource/evansport-build/source/linux-3.x/usr/include/scsi/fc/$$F; done; touch /synosrc2/GPLSource/evansport-build/source/linux-3.x/usr/include/scsi/fc/.install
