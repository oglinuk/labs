package main

import (
	"os"
)

func main() {
	var err error

	if err = os.Mkdir("hw-example", 0744); err != nil {
		panic(err)
	}

	if err = os.Chdir("hw-example"); err != nil {
		panic(err)
	}

	cf, err := os.Create("hello.txt")
	if err != nil {
		panic(err)
	}
	defer cf.Close()

	cf.WriteString("world from hw_os example!")
}
