#!/bin/bash

rm -fr build/*
mkdir -p build
cd srcExtension

# refresh with latest DLL build
echo "Copying last DLL build (if exist) ..."
dll="../../xpcom/VCproject/Debug/GreenFox.dll"
platform="WINNT_x86-msvc"
if [[ -a $dll ]]; then 
	cp -f $dll platform/$platform/components/
fi

# build XPI
echo "Packaging XPI..."
xpi_contents="chrome components/*.xpt defaults platform chrome.manifest install.rdf *.txt"
zip -r ../build/greenfox.xpi $xpi_contents -x '*/.svn/*' -x '*~' 

