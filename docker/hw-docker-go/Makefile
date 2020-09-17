output: build
	docker run --name hw-docker-go go-docker

build:
	docker build . -t go-docker

clean:
	docker stop hw-docker-go
	docker rm hw-docker-go