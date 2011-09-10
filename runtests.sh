#!/usr/bin/env bash

pushd .
cd bin
LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH ./cpr_test
popd
