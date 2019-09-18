package main

import (
	"fmt"
	"log"
	"time"

	"golang.org/x/net/websocket"
)

func startClient() {
	origin := "http://localhost/"
	url := "ws://localhost:9001/ws"
	ws, err := websocket.Dial(url, "", origin)
	if err != nil {
		log.Fatal(err)
	}

	_, err = ws.Write([]byte("Hello world!\n"))
	if err != nil {
		log.Fatal(err)
	}

	var msg = make([]byte, 512)
	var n int
	if n, err = ws.Read(msg); err != nil {
		log.Fatal(err)
	}
	fmt.Printf("Received: %s\n", msg[:n])

	i := 0
	for {
		payload := []byte(fmt.Sprintf("Hello world number %d\n", i))
		_, err := ws.Write(payload)
		if err != nil {
			log.Fatal(err)
		}

		var msg = make([]byte, 512)
		var n int
		if n, err = ws.Read(msg); err != nil {
			log.Fatal(err)
		}
		fmt.Printf("Received: %s\n", msg[:n])

		i++
		time.Sleep(time.Second * 1)
	}
}
