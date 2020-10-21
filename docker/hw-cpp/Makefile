output: build
	docker run --name hw-docker-cpp cpp-docker

build:
	docker build . -t cpp-docker

clean:
	docker stop hw-docker-cpp
	docker rm hw-docker-cpp