#!/bin/bash

if [[ ! -d build ]];
  then
  mkdir build;
fi;

cd build
cmake ..
make -j12 install
cd ..
