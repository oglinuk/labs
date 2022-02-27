package main

import (
	"io"
	"os"
	"strings"

	"github.com/dsnet/compress/bzip2"
)

// decompressBz2 opens the given filename, creates a file from filename
// without .bz2 extension, create a bz2.Reader, and copy the contents of
// the given filename to the created file
func decompressBz2(filename string) error {
	compressed, err := os.Open(filename)
	if err != nil {
		return err
	}
	defer compressed.Close()

	stripped := strings.Split(filename, ".bz2")[0]
	f, err := os.Create(stripped)
	if err != nil {
		return err
	}
	defer f.Close()

	bzr, err := bzip2.NewReader(compressed, nil)
	if err != nil {
		return err
	}

	_, err = io.Copy(f, bzr)
	if err != nil {
		return err
	}

	return nil
}
