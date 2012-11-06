#!/bin/bash

function check_return_value()
{
  if [ $1 -ne 0 ];
  then
    exit 1
  fi
}

mkdir _build_/test-reports -p
cd _build_
cmake ..
check_return_value $?

make -j8
check_return_value $?

./bin/tfmtests --gtest_output=xml:test-reports/tfmtests.xml
