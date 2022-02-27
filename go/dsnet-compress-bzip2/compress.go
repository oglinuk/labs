package main

import (
	"fmt"
	"io"
	"os"

	"github.com/dsnet/compress/bzip2"
)

// compressBz2 opens the given filename, creates a .bz2 file, creates a
// bz2.Writer, then copies the contents of filename to the .bz2 file
func compressBz2(filename string) error {
	uncompressed, err := os.Open(filename)
	if err != nil {
		return nil
	}
	defer uncompressed.Close()

	bzf, err := os.Create(fmt.Sprintf("%s.bz2", filename))
	if err != nil {
		return nil
	}

	bzw, err := bzip2.NewWriter(bzf, &bzip2.WriterConfig{Level: 6})
	if err != nil {
		return nil
	}
	defer bzw.Close()

	_, err = io.Copy(bzw, uncompressed)
	if err != nil {
		return nil
	}

	return nil
}
