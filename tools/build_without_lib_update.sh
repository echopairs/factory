#!/bin/bash
which cmake >/dev/null 2>&1 || { echo "build requires cmake but nothig is found"; exit 1; }
script=$(readlink -f "$0")
route=$(dirname "$script")
if [ -d "$route/../build" ]; then
    rm -rf $route/../build
fi
mkdir -p $route/../build || exit 2
cd $route/../build
cmake .. -G "Unix Makefiles"
make -j 4