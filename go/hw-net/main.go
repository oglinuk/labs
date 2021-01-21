package main

import (
	"fmt"
	"log"
	"net"
	"net/http"
)

var (
	PORT = 65535
)

func main() {
	go func() {
		http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
			fmt.Fprintf(w, "Hello world!")
		})
		fmt.Printf("Serving at :%d ...\n", PORT)
		log.Fatal(http.ListenAndServe(fmt.Sprintf(":%d", PORT), nil))
	}()

	conn, err := net.Dial("tcp", fmt.Sprintf("localhost:%d", PORT))
	if err != nil {
		panic(err)
	}

	fmt.Println("Dial successful ...")
	fmt.Printf("%s\n", conn)

	for{}
}
