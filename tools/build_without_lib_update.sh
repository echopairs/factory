#!/bin/bash

which cmake >/dev/null 2>&1 || { echo "build requires cmake but nothig is found"; exit 1; }
script=$(readlink -f "$0")
route=$(dirname "$script")
VERSION=`cat ${route}/../version`
if [ -d "$route/../build" ]; then
    rm -rf $route/../build
fi
mkdir -p $route/../build || exit 2

cd $route/../build
cmake .. -G "Unix Makefiles"
make -j 4

cp -rf $route/../doc $route/../build/release/

sh $route/strip.sh || exit 4

cd $route/../build 
checkinstall -R --install=no --default --pkgname=factory --pkgversion=${VERSION} --pakdir=${route}/../tools --fstrans=no || exit 5


cp $route/Makefile.debuginfo ${route}/../build/release/Makefile || exit 6
cd $route/../build/release/
checkinstall -R --install=no --default --pkgname=factory-debug --pkgversion=${VERSION} --pakdir=${route}/../tools --fstrans=no || exit 5
