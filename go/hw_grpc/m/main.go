package main

import (
	"log"
	"net"

	"gitlab.com/OGLinuk/mdas/m/server"
	mpb "gitlab.com/OGLinuk/mdas/proto/m"
	"google.golang.org/grpc"
)

func main() {
	lis, err := net.Listen("tcp", "0.0.0.0:9001")
	if err != nil {
		log.Fatalf("Failed to listen: %v", err)
	}

	log.Println("Server running on port 9001 ...")

	srvr := grpc.NewServer()
	mpb.RegisterMServiceServer(srvr, &server.Server{})
	if err := srvr.Serve(lis); err != nil {
		log.Fatalf("Failed to serve: %v", err)
	}
}
