FROM base-cpp-docker:0.1.0 AS build
ADD . /src
WORKDIR /src
RUN cmake . && make

FROM ubuntu:18.04
WORKDIR /opt/hello-cpp
COPY  --from=build /src/main ./
CMD ["./main"]