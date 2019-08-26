package main

import (
	"os"
)

func main() {
	var err error

	if err = os.Mkdir("hw_example", 0777); err != nil {
		panic(err)
	}

	if err = os.Chdir("hw_example"); err != nil {
		panic(err)
	}

	cf, err := os.Create("hello.txt")
	if err != nil {
		panic(err)
	}
	defer cf.Close()

	cf.WriteString("world from hw_os example!")
}