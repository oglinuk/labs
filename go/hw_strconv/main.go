package main

import (
	"fmt"
	"strconv"
)

func main() {
	meaningOfLife := 42
	fortuneNumber := "7"

	intToStr := strconv.Itoa(meaningOfLife)
	strToInt, err := strconv.Atoi(fortuneNumber)
	if err != nil {
		panic(err)
	}

	fmt.Printf("%s is a string\n%d is an int\n", intToStr, strToInt)
}
