package main

import (
	"flag"
	"log"
)

var (
	target = flag.String("t", "go.sum", "File to operate on")
	comp = flag.Bool("c", false, "Compress target file")
	decomp = flag.Bool("d", false, "Decompress target file")
)

func main() {
	flag.Parse()

	if !*comp && !*decomp {
		flag.Usage()
	}

	if *comp {
		if err := compressBz2(*target); err != nil {
			log.Fatalf("compressBz2: %s\n", err.Error())
		}
		log.Printf("compressed %s ...\n", *target)
	}

	if *decomp {
		if err := decompressBz2(*target); err != nil {
			log.Fatalf("decompressBz2: %s\n", err.Error())
		}
		log.Printf("decompressed %s ...\n", *target)
	}
}
