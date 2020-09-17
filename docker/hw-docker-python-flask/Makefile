output: build
	docker run -d --name hw-docker-python-flask -p 9001:9001 python-flask-docker

build:
	docker build . -t python-flask-docker

clean:
	docker stop hw-docker-python-flask
	docker rm hw-docker-python-flask