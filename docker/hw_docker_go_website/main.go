package main

import (
	"fmt"
	"log"
	"net/http"
)

func handler(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "Hello world from the webserver in docker!")
}

func main() {
	http.HandleFunc("/", handler)
	log.Printf("Serving on localhost:9001 ...")
	log.Fatal(http.ListenAndServe("0.0.0.0:9001", nil))
}
