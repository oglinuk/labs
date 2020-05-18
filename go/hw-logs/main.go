package main

import (
	"log"
	"os"
)

// Source: https://yourbasic.org/golang/log-to-file/
func main() {
	f, err := os.OpenFile("hw-logs.log",
		os.O_APPEND|os.O_CREATE|os.O_WRONLY, 0644)
	if err != nil {
		log.Println(err)
	}
	defer f.Close()

	log.SetOutput(f)

	log.Println("Hello world from hw-logs!")
}
