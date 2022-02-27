package main

import (
	"bufio"
	"flag"
	"fmt"
	"io"
	"log"
	"math/rand"
	"os"
	"strconv"
	"sync"
	"time"
)

var (
	numOfPlays = flag.Int("n", 1, "Number of times to play")
	difficulty = flag.Int("d", 10, "Difficulty")
	letBot     = flag.Bool("b", false, "Let the bot play")
	logGuesses = flag.Bool("l", false, "Write guesses to logs")
)

func getGuess() int {
	var iGuess int
	var err error

	scanner := bufio.NewScanner(os.Stdin)

	fmt.Print("Guess: ")

	for scanner.Scan() {
		iGuess, err = strconv.Atoi(scanner.Text())
		if err != nil {
			fmt.Println("Please enter a number ...")
			getGuess()
		}
		break
	}

	return iGuess
}

func play(diff int) {
	rand.Seed(time.Now().UTC().UnixNano())
	rngNum := rand.Intn(diff)
	guess := -1
	guesses := 0

	for {
		if *letBot {
			guess = botPlay()
		} else {
			guess = getGuess()
		}
		guesses++

		if guess == rngNum {
			log.Printf("You win! It took you %d guesses!\n", guesses)
			break
		} else if guess > rngNum {
			log.Printf("Guess %d was too high!\n", guess)
		} else if guess < rngNum {
			log.Printf("Guess %d was too low!\n", guess)
		}
	}
}


func botPlay() int {
	rand.Seed(time.Now().UTC().UnixNano())
	return rand.Intn(*difficulty)
}

func main() {
	flag.Parse()

	if *logGuesses {
		f, err := os.OpenFile("logfile", os.O_RDWR|os.O_CREATE|os.O_APPEND, 0770)
		if err != nil {
			panic(err)
		}
		defer f.Close()

		wrt := io.MultiWriter(os.Stdout, f)

		log.SetOutput(wrt)
	}

	if *letBot {
		wg := &sync.WaitGroup{}
		for i := 0; i < *numOfPlays; i++ {
			wg.Add(1)
			go func() {
				defer wg.Done()
				play(*difficulty)
			}()
		}
		wg.Wait()
	} else {
		for i := 0; i < *numOfPlays; i++ {
			play(*difficulty)
		}
	}
}
