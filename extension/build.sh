#!/bin/bash

rm -fr build/*
mkdir -p build
cd srcExtension

# refresh with latest library built
echo "Copying last library built (if exist) ..."
# dll="../../library/greenfox.dll"
dll="../../library/greenfox.so"
if [[ -a $dll ]]; then 
	cp -f $dll components/
	echo "New DLL updated"
fi

# build XPI
echo "Packaging XPI..."
xpi_contents="chrome defaults components chrome.manifest install.rdf"
zip -r ../build/greenfox.xpi $xpi_contents -x '*/.svn/*' -x '*~' 

