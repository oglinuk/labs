package main

import (
	"fmt"

	JSON "github.com/oglinuk/labs/go/std/encoding/json"
)

func main() {
	encoded, err := JSON.EncodeToString(map[string]string{"hello":"json encoding!"})
	if err != nil {
		fmt.Errorf("JSON.Encode: %s\n", err.Error())
	}

	fmt.Println(encoded)
}
