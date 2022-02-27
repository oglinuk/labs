package main

import (
	"fmt"
)

// hello returns the formatted result of "hello" and the given input
func hello(msg string) string {
	return fmt.Sprintf("hello%s", msg)
}
