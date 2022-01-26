FROM golang:1.17 as builder

WORKDIR /go/src
ADD go.* . 
RUN go mod download

ADD main.go /go/src
ENV CGO_ENABLED=0
RUN go install

FROM scratch
COPY --from=builder /go/bin/hello /hello
EXPOSE 9001
CMD ["/hello"]
