package main

import (
	"flag"
	"fmt"
	"io"
	"os"

	"github.com/dsnet/compress/bzip2"
)

var (
	filename = "lorem-ipsum"

	comp   = flag.Bool("c", false, "Compress")
	decomp = flag.Bool("d", false, "Decompress")
)

func decompress() {
	compressed := fmt.Sprintf("%s.txt.bz2", filename)

	bzf, err := os.Open(compressed)
	if err != nil {
		panic(err)
	}
	defer bzf.Close()

	f, err := os.Create(fmt.Sprintf("%s.txt", filename))
	if err != nil {
		panic(err)
	}
	defer f.Close()

	bzr, err := bzip2.NewReader(bzf, nil)
	if err != nil {
		panic(err)
	}
	defer bzr.Close()

	if _, err = io.Copy(f, bzr); err == nil {
		if err = os.Remove(compressed); err != nil {
			panic(err)
		}
	}
}

func compress() {
	uncompressed := fmt.Sprintf("%s.txt", filename)

	f, err := os.Open(uncompressed)
	if err != nil {
		panic(err)
	}
	defer f.Close()

	bzf, err := os.Create(fmt.Sprintf("%s.txt.bz2", filename))
	if err != nil {
		panic(err)
	}
	defer bzf.Close()

	bzw, err := bzip2.NewWriter(bzf, &bzip2.WriterConfig{Level: 6})
	if err != nil {
		panic(err)
	}
	defer bzw.Close()

	if _, err = io.Copy(bzw, f); err == nil {
		if err = os.Remove(uncompressed); err != nil {
			panic(err)
		}
	}
}

func main() {
	flag.Parse()

	if !*comp && !*decomp {
		flag.Usage()
	}

	if *comp {
		compress()
	}

	if *decomp {
		decompress()
	}
}
