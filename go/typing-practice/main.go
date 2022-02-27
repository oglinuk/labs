package main

import (
	"bufio"
	"fmt"
	"log"
	"math/rand"
	"os"
	"time"
)

func getGuess(bs *bufio.Scanner) string {
	bs.Scan()
	word := bs.Text()
	return word
}

func getRandWord(words []string) string {
	return words[rand.Intn(len(words))]
}

func loadWords() []string {
	var words []string

	f, err := os.Open("wordlist.txt")
	if err != nil {
		log.Fatal(err)
	}

	bs := bufio.NewScanner(f)

	for bs.Scan() {
		words = append(words, bs.Text())
	}

	return words
}

func main() {
	rand.Seed(time.Now().Unix())
	total, totalCorrect := 0, 0
	words := loadWords()
	bs := bufio.NewScanner(os.Stdin)
	timeLimit := time.Now().Unix() + 60

	for {
		if time.Now().Unix() >= timeLimit {
			break
		}
		total++
		word := getRandWord(words)
		fmt.Println(word)

		guess := getGuess(bs)
		if guess == word {
			fmt.Println("correct")
			totalCorrect++
		}
	}

	fmt.Printf("You got %d out of %d correct!\n", totalCorrect, total)
}
