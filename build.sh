#/bin/sh
. ./config.sh

cd ${PHAROCROSSROOT}/pharo-vm/image
./pharo generator.image eval "${CONFIGNAME} new  
		generateSources; generate."

cd ${PHAROCROSSROOT}/pharo-vm/build
sh ../scripts/extract-commit-info.sh

echo "
SET(CMAKE_SYSTEM_NAME Linux)
SET(CMAKE_SYSTEM_VERSION 1)
set(CMAKE_SYSTEM_PROCESSOR arm)

SET(CMAKE_C_COMPILER ${PHAROCROSSROOT}/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/bin/arm-linux-gnueabihf-gcc)
SET(CMAKE_CXX_COMPILER ${PHAROCROSSROOT}/tools/aarm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/bin/arm-linux-gnueabihf-g++)

# where is the target environment - we mounted it using sshfs
SET(CMAKE_FIND_ROOT_PATH ${PHAROCROSSROOT})

# search for programs in the build host directories
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# for libraries and headers in the target directories
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
" >> toolchainRaspPi.cmake

chroot ${PHAROCROSSROOT} cmake -DCMAKE_TOOLCHAIN_FILE=toolchainRaspPi.cmake .
chroot ${PHAROCROSSROOT} make