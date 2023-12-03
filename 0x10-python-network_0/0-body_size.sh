#!/bin/bash
# printing the size of the http response
curl -sI "$1" | grep -i 'content-length' | cut -d ' ' -f2
