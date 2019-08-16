FROM golang:1.10.0
ADD . /go/src/mserver
WORKDIR /go/src/mserver
RUN go get
RUN go build -o main .
EXPOSE 9001
CMD ["./main"]