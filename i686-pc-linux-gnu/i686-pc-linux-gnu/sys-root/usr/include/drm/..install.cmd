cmd_/synosrc2/GPLSource/evansport-build/source/linux-3.x/usr/include/drm/.install := perl scripts/headers_install.pl /synosrc2/GPLSource/evansport-build/source/linux-3.x/include/drm /synosrc2/GPLSource/evansport-build/source/linux-3.x/usr/include/drm x86 drm.h drm_mode.h drm_sarea.h i810_drm.h i915_drm.h mga_drm.h nouveau_drm.h r128_drm.h radeon_drm.h savage_drm.h sis_drm.h via_drm.h vmwgfx_drm.h; perl scripts/headers_install.pl /synosrc2/GPLSource/evansport-build/source/linux-3.x/include/drm /synosrc2/GPLSource/evansport-build/source/linux-3.x/usr/include/drm x86 ; for F in ; do echo "\#include <asm-generic/$$F>" > /synosrc2/GPLSource/evansport-build/source/linux-3.x/usr/include/drm/$$F; done; touch /synosrc2/GPLSource/evansport-build/source/linux-3.x/usr/include/drm/.install
