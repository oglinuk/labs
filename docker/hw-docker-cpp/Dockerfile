FROM ubuntu:20.04
ARG DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y build-essential cmake
ADD . /src
WORKDIR /src/build
RUN cmake .. && make
CMD ["./main"]