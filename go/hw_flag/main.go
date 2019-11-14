package main

import (
	"flag"
	"fmt"
)

func main() {
	name := flag.String("n", "", "Your name")
	flag.Parse()

	if *name == "" {
		flag.Usage()
	} else {
		fmt.Printf("Hello %s!", *name)
	}
}
