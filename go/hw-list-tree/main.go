package main

import (
	"fmt"
	"os"
	"os/user"
	"path/filepath"
	"time"
)

var (
	cnt int
)

func main() {
	sTime := time.Now()
	cuser, err := user.Current()
	if err != nil {
		panic(err)
	}

	err = filepath.Walk(cuser.HomeDir, func(path string, info os.FileInfo, err error) error {
		if err != nil {
			fmt.Printf("Errored: %s", err.Error())
		}

		fmt.Printf("Walked: %s ...\n", path)
		cnt++
		return nil
	})

	if err != nil {
		fmt.Printf("Failed to filepath.Walk: %s\n", err.Error())
	}

	fmt.Printf("Walked %d in %s\n", cnt, time.Since(sTime))
}
