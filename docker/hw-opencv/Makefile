XHOST="/tmp/.X11-unix"
VIDEO="/dev/video0"

# Either run 'python3 run.py' or './build/main' inside the container
output: build
	docker run --name hw-docker-opencv -it -e DISPLAY -v ${XHOST}:${XHOST} --device ${VIDEO}:${VIDEO} opencv-docker

build:
	docker build . -t opencv-docker

clean:
	docker stop hw-docker-opencv
	docker rm hw-docker-opencv