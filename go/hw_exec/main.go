package main

import (
	"bytes"
	"fmt"
	"os/exec"
)

func main() {
	var out bytes.Buffer

	cmd := exec.Command("ls")

	cmd.Stdout = &out

	if err := cmd.Run(); err != nil {
		panic(err)
	}

	fmt.Println(out.String())
}
