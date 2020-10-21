output: build
	docker run --name hw-docker-multistage-build -t cpp-docker:1.0.0

build:
	docker build ./first-stage -t base-cpp-docker:0.1.0
	docker build ./second-stage -t cpp-docker:1.0.0

clean:
	docker stop hw-docker-multistage-build
	docker rm hw-docker-multistage-build