package main

import (
	"context"
	"fmt"
	"log"
	"math/rand"
	"net"
	"os"
	"os/signal"
	"time"

	gpb "../proto"
	"google.golang.org/grpc"
)

type server struct{}

var (
	err error
)

func main() {
	SHOST := "0.0.0.0"
	SPORT := 9001

	log.Println("Starting server ...")

	listener, err := net.Listen("tcp", fmt.Sprintf("%s:%d", SHOST, SPORT))
	if err != nil {
		log.Fatalf("Port %d already in use ...", SPORT)
	}

	srvr := grpc.NewServer()
	gpb.RegisterDiceGameServiceServer(srvr, &server{})

	go func() {
		if err := srvr.Serve(listener); err != nil {
			log.Fatalf("Failed to start server: %v", err)
		}
	}()
	log.Printf("Server running on %s:%d ...", SHOST, SPORT)

	ch := make(chan os.Signal)
	signal.Notify(ch, os.Interrupt)
	<-ch

	log.Println("Shutting server down ...")
	srvr.Stop()
	listener.Close()

	log.Println("Shutdown complete ...")
}

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
