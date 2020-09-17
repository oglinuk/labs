output: build
	docker run --name hw-docker-python python-docker

build:
	docker build . -t python-docker

clean:
	docker stop hw-docker-python
	docker rm hw-docker-python