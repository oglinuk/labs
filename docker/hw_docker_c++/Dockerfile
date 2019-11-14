FROM ubuntu:18.04
ADD . /src
WORKDIR /src
RUN apt-get update && apt-get install -y build-essential cmake
RUN cmake . && make
CMD ["./main"]