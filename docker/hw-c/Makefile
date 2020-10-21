output: main
	gcc main.c -o main

build:
	docker build . -t c-docker
	docker run --name hw-docker-c c-docker

clean:
	docker stop hw-docker-c
	docker rm hw-docker-c