#!/bin/bash

rm -fr build/*
mkdir -p build
cd srcExtension

# refresh with latest DLL build
echo "Copying last DLL build (if exist) ..."
dll="../../library/greenfox.dll"
if [[ -a $dll ]]; then 
	cp -f $dll components/
	echo "New DLL updated"
fi

# build XPI
echo "Packaging XPI..."
xpi_contents="chrome defaults platform components chrome.manifest install.rdf"
zip -r ../build/greenfox.xpi $xpi_contents -x '*/.svn/*' -x '*~' 

