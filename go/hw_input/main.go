package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	fmt.Println("\n\nType something, then press enter ...\n")

	for scanner.Scan() {
		fmt.Printf("\nYou said: %s\n\n", scanner.Text())
	}
}
