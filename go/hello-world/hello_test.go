package main

import (
	"testing"
)

// TestHello ensures the expected string is returned
func TestHello(t *testing.T) {
	cases := []struct {
		input, expected string
	}{
		{", world!", "hello, world!"},
		{" to no one.", "hello to no one."},
		{" and goodbye.", "hello and goodbye."},
		{"", "hello"},
	}

	for _, c := range cases {
		actual := hello(c.input)
		if actual != c.expected {
			t.Errorf("Expected: %s | Actual: %s\n", c.expected, actual)
		}
	}
}
