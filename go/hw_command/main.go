package main

import (
	"bytes"
	"fmt"
	"log"
	"os/exec"
)

func main() {
	var out bytes.Buffer

	cmd := exec.Command("ls")

	cmd.Stdout = &out

	err := cmd.Run()
	if err != nil {
		log.Fatal(err)
	}

	fmt.Println(out.String())
}
