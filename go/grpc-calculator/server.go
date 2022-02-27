package main

import (
	"context"
	"log"
	"net"

	mpb "github.com/oglinuk/labs/go/grpc-calculator/proto"
	"google.golang.org/grpc"
)

type server struct{}

func (s *server) Multiply(ctx context.Context, req *mpb.MultiplyRequest) (*mpb.MultiplyResponse, error) {
	a, b := req.GetA(), req.GetB()

	result := a * b

	return &mpb.MultiplyResponse{N: result}, nil
}

func initServer() {
	lis, err := net.Listen("tcp", "0.0.0.0:10001")
	if err != nil {
		log.Fatalf("Failed to listen: %v", err)
	}

	log.Println("Server running on port 10001 ...")

	srvr := grpc.NewServer()
	mpb.RegisterMServiceServer(srvr, &server{})

	if err := srvr.Serve(lis); err != nil {
		log.Fatalf("Failed to serve: %v", err)
	}
}
