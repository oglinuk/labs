package main

import (
	"context"
	"fmt"
	"log"
	"math/rand"
	"net"
	"time"

	gpb "./proto"
	"google.golang.org/grpc"
)

type server struct{}

func (s *server) Play(ctx context.Context, req *gpb.TurnRequest) (*gpb.TurnResponse, error) {
	rand.Seed(time.Now().UTC().UnixNano())

	var won bool

	serverRoll := rand.Int31n(42)
	clientRoll := req.GetRoll()

	won = false
	if clientRoll > serverRoll {
		won = true
	}

	resp := &gpb.TurnResponse{
		ClientRoll: clientRoll,
		ServerRoll: serverRoll,
		Won:        won,
	}

	return resp, nil
}

func initServer() {
	SHOST := "0.0.0.0"
	SPORT := 8001

	lis, err := net.Listen("tcp", fmt.Sprintf("%s:%d", SHOST, SPORT))
	if err != nil {
		log.Fatalf("Port %d already in use ...", SPORT)
	}

	log.Printf("Server running on %s:%d ...", SHOST, SPORT)

	srvr := grpc.NewServer()
	gpb.RegisterDiceGameServiceServer(srvr, &server{})

	go func() {
		if err := srvr.Serve(lis); err != nil {
			log.Fatalf("Failed to start server: %v", err)
		}
	}()
}
