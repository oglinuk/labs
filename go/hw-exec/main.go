package main

import (
	"os"
	"os/exec"
)

func main() {
	cmd := exec.Command("ls")

	cmd.Stdout = os.Stdout

	if err := cmd.Run(); err != nil {
		panic(err)
	}
}
