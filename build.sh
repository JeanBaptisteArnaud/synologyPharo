#/bin/sh
. ./config.sh
cd ${PHAROCROSSROOT}

cd ${PHAROCROSSROOT}/pharo-vm/image
./pharo generator.image eval "PharoVMBuilder buildUnix32"

cd ${PHAROCROSSROOT}/pharo-vm/build
sh ../scripts/extract-commit-info.sh

echo "
SET(CMAKE_SYSTEM_NAME Linux)
SET(CMAKE_SYSTEM_VERSION 1)
set(CMAKE_SYSTEM_PROCESSOR x86)

SET(CMAKE_C_COMPILER ${PHAROCROSSROOT}/i686-pc-linux-gnu/bin/i686-pc-linux-gnu-gcc)
SET(CMAKE_CXX_COMPILER ${PHAROCROSSROOT}/i686-pc-linux-gnu/bin/i686-pc-linux-gnu-g++)

# where is the target environment - we mounted it using sshfs
SET(CMAKE_FIND_ROOT_PATH ${PHAROCROSSROOT}/i686-pc-linux-gnu/)

# search for programs in the build host directories
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# for libraries and headers in the target directories
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
" >> toolchainRaspPi.cmake

cmake -DCMAKE_TOOLCHAIN_FILE=toolchainRaspPi.cmake .
make
