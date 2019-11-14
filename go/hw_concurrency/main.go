package main

import (
	"log"
	"sync"
)

func main() {
	wg := &sync.WaitGroup{}
	for i := 0; i < 10; i++ {
		wg.Add(1)
		go func(i int) {
			defer wg.Done()
			printNumber(i)
		}(i)
	}
	wg.Wait()
}

func printNumber(i int) {
	log.Printf("Printing %d ...", i)
}
