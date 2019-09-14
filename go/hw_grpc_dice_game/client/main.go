package main

import (
	"bufio"
	"context"
	"fmt"
	"log"
	"math/rand"
	"os"
	"time"

	gpb "../proto"
	"google.golang.org/grpc"
)

var (
	c   gpb.DiceGameServiceClient
	err error
)

func rollDice() int32 {
	rand.Seed(time.Now().UTC().UnixNano())
	return rand.Int31n(42)
}

func play() {
	for {
		roll := rollDice()

		result, _ := c.Play(context.Background(), &gpb.TurnRequest{Roll: roll})

		var winner string

		winner = "Server"
		if result.Won {
			winner = "You"
		}

		fmt.Printf("Your roll: %d\nServer's roll: %d\nWinner: %s\n\n",
			result.ClientRoll,
			result.ServerRoll,
			winner)

		fmt.Print("Press 'Enter' to play again...\n")
		bufio.NewReader(os.Stdin).ReadBytes('\n')
	}
}

func main() {
	SHOST := "0.0.0.0"
	SPORT := 9001

	log.Printf("Client connected to grpc server on %s:%d ...", SHOST, SPORT)
	conn, err := grpc.Dial(fmt.Sprintf("%s:%d", SHOST, SPORT), grpc.WithInsecure())
	if err != nil {
		panic(err)
	}

	c = gpb.NewDiceGameServiceClient(conn)

	play()
}
