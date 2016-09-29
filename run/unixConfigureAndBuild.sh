#!/bin/bash

RUN_DIR=$(pwd)

if [[ ! -d _build ]];
  then
  mkdir _build;
fi;

cd _build
cmake -DNEW_PROJECT="" ../..
make -j12
cd ..
