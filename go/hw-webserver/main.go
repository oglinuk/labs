package main

import (
	"fmt"
	"log"
	"net/http"
)

func handler(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "Hello world from the hw-webserver!")
}

// https://golang.org/doc/articles/wiki/#tmp_3
func main() {
	http.HandleFunc("/", handler)
	log.Printf("Serving on localhost:9001 ...")
	log.Fatal(http.ListenAndServe(":9001", nil))
}
