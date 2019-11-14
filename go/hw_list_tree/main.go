package main

import (
	"fmt"
	"io/ioutil"
	"os/user"
	"path/filepath"
	"time"
)

func main() {
	cuser, err := user.Current()
	if err != nil {
		panic(err)
	}

	if err = listTree(cuser.HomeDir, ""); err != nil {
		panic(err)
	}
}

// Source: https://stackoverflow.com/a/49233329
func listTree(rootBase, currentBase string) error {
	files, err := ioutil.ReadDir(rootBase)
	if err != nil {
		return err
	}

	for _, f := range files {
		fname := f.Name()

		current, err := filepath.Abs(rootBase)
		if err != nil {
			return err
		}

		if !f.IsDir() {
			fmt.Printf("File: %s/%s\n", current, fname)
		} else {
			fmt.Printf("Dir: %s/%s\n", current, fname)

			newRootBase := fmt.Sprintf("%s/%s", rootBase, fname)
			newCurrentBase := fmt.Sprintf("%s/%s", currentBase, fname)

			listTree(newRootBase, newCurrentBase)
		}

		time.Sleep(time.Millisecond * 10)
	}

	return nil
}
