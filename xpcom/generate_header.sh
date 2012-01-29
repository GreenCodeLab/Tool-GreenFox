#!/bin/bash

# Green Code Lab
# Generate header file corresponding to IDL definition
# @see documentation https://developer.mozilla.org/en/XPIDL/pyxpidl

# Import config file
source config.cfg 

# Generate headers
# python $PYTHON_HEADER_GENERATOR_PATH -I $PYTHON_HEADER_INCLUDE_PATH -o clIGreenFox.h clIGreenFox.idl
python $PYTHON_HEADER_GENERATOR_PATH -I $PYTHON_HEADER_INCLUDE_PATH -o nsISample.h nsISample.idl