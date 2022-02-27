package main

import (
	"fmt"
	"testing"

	//"github.com/stretchr/testify/assert"
)

// TestFmtSprintf ensures the expected string is returned
func TestFmtSprintf(t *testing.T) {
	cases := map[string][]interface{}{
		"hello, sprintf!": []interface{}{"hello,", "sprintf!"},
		"string interpolation!": []interface{}{"string", "interpolation!"},
	}

	for expected, in := range cases {
		actual := fmt.Sprintf("%s %s", in...)
		//assert.Equal(t, expected, actual)
		if actual != expected {
			t.Errorf("\nExpected: %v\n  Actual: %v\n", expected, actual)
		}
	}
}
