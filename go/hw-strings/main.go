package main

import (
	"fmt"
	"strings"
)

func main() {
	hw := "HELLO WORLD!"
	hg := "hello gophers!"

	if strings.Contains(hg, "gophers") {
		fmt.Println(hg)
	}

	if strings.HasSuffix(hw, "!") {
		fmt.Println(hw)
	}

	fmt.Println(strings.ToUpper(hg))
	fmt.Println(strings.ToLower(hw))

	fmt.Println(strings.Replace(hg, "gophers!", "from strings!", -1))
	fmt.Println(strings.Replace(hw, "L", "1", 2))

	fmt.Println(strings.TrimSuffix(hg, "!"))
	fmt.Println(strings.Trim(hw, "H"))
}
