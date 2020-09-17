package main

import (
	"bufio"
	"fmt"
	"log"
	"math/rand"
	"os"
	"time"
)

var (
	filepath = "wordList.txt"
)

func getGuess() string {
	r := bufio.NewReader(os.Stdin)
	word, _ := r.ReadString('\n')
	return word
}

func getRandWord(words []string) string {
	return words[rand.Intn(len(words))]
}

func loadWords() []string {
	var words []string

	f, err := os.Open(filepath)
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
	words := loadWords()
	timeLimit := time.Now().Unix() + 60
	total, totalCorrect := 0, 0

	for {
		total++
		word := getRandWord(words)
		fmt.Println(word)
		guess := getGuess()
		if guess == word {
			totalCorrect++
		}
		if time.Now().Unix() >= timeLimit {
			break
		}
	}
	fmt.Printf("You got %d out of %d correct!", totalCorrect, total)
}
