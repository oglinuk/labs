FROM golang:1.10.0
ADD . /go/src/code
WORKDIR /go/src/code
RUN go build -o main .
CMD ["./main"]