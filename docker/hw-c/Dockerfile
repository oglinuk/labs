FROM ubuntu:20.04
ARG DEBIAN_FRONTEND=noninteractive
ADD . /src
WORKDIR /src
RUN apt-get update && apt-get install -y build-essential make && make
CMD ["./main"]