#!/bin/bash

if [[ ! $VERSION ]]; then
	echo "No version set, defaulting to latest ..."
	VERSION="latest"
fi

IMAGETAG="docv:$VERSION"

echo "Building $IMAGETAG ..."

docker build . -t $IMAGETAG

XHOST="/tmp/.X11-unix"
VIDEO="/dev/video0"

docker run -it -e DISPLAY -v $XHOST:$XHOST --device $VIDEO:$VIDEO $IMAGETAG

echo "Run either 'python3 run.py' or './build/main' ..."