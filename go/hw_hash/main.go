package main

import (
	"crypto/sha256"
	"encoding/hex"
	"fmt"
)

func main() {
	hasher := sha256.New()
	hasher.Write([]byte("hello world!"))
	fmt.Println(hex.EncodeToString(hasher.Sum(nil)))
}
