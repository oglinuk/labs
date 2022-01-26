package main

import (
	"fmt"
	"log"
	"net/http"
	"os"
)

func main() {
	PORT := os.Getenv("PORT")
	if PORT == "" {
		PORT = "9001"
	}

	http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		fmt.Fprintf(w, "hello, world!")
	})

	log.Println("Server is running ...")
	log.Fatal(http.ListenAndServe(fmt.Sprintf("0.0.0.0:%s", PORT), nil))
}
