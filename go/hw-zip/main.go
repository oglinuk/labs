package main

import (
	"archive/zip"
	"bufio"
	"log"
	"os"
)

func main() {
	createZip()
	unZip()
}

func createZip() {
	f, err := os.Create("hw.zip")
	if err != nil {
		panic(err)
	}

	zw := zip.NewWriter(f)
	defer zw.Close()

	fileNames := []string{"hello", "world", "zip"}
	fileContent := []string{"world", "hello", "hw"}

	for i, fname := range fileNames {
		zf, err := zw.Create(fname)
		if err != nil {
			panic(err)
		}

		zf.Write([]byte(fileContent[i]))
	}
}

func unZip() {
	zr, err := zip.OpenReader("hw.zip")
	if err != nil {
		panic(err)
	}
	defer zr.Close()

	for _, zf := range zr.File {
		f, err := zf.Open()
		if err != nil {
			panic(err)
		}

		scanner := bufio.NewScanner(f)
		for scanner.Scan() {
			log.Println(scanner.Text())
		}
	}
}
