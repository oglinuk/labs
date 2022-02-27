package main

import (
	"fmt"

	SHA256 "github.com/oglinuk/labs/go/std/crypto/sha256"
)

func main() {
	fmt.Println(SHA256.GenerateHash("hello, crypto!"))
}
