#!/bin/bash

RUN_DIR=$(pwd)

if [[ ! -d _build ]];
  then
  mkdir _build;
fi;

cd _build
cmake -DINSTALL_DIR=$RUN_DIR ../..
make -j12 install
cd ..
