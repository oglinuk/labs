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

	fmt.Printf("%s is an int converted to string\n", intToStr)
	fmt.Printf("%d is an string converted to int\n", strToInt)
}
