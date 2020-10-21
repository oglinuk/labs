output: build
	docker run -d --name hw-docker-go-website -p 9001:9001 go-docker-website

build:
	docker build . -t go-docker-website

clean:
	docker stop hw-docker-go-website
	docker rm hw-docker-go-website