FROM golang:1.10.0
ADD . /go/src/mclient
WORKDIR /go/src/mclient
RUN go get
RUN go build -o main .
EXPOSE 9002
CMD ["./main"]