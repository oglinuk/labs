package main

import (
	"bufio"
	"flag"
	"fmt"
	"os"
)

func main() {
	largeFile := flag.String("f", "", "Filename of a large file")
	flag.Parse()

	if *largeFile == "" {
		flag.Usage()
		return
	}

	if err := scanLargeFile("logfile"); err != nil {
		panic(err)
	}
}

func scanLargeFile(filename string) error {
	// os.Open is better since ioutil.ReadFile
	// stores in memory which is bad for files > 1GB
	f, err := os.Open(filename)
	if err != nil {
		return err
	}

	bs := bufio.NewScanner(f)

	for bs.Scan() {
		fmt.Println(bs.Text())
	}

	return nil
}
