package main

import (
	"bytes"
	"fmt"
	"testing"

	//"github.com/stretchr/testify/assert"
)

// TestFmtPrint ensures the bytes.Buffer contains the expected result
func TestFmtPrint(t *testing.T) {
	cases := map[interface{}]interface{}{
		"hello, fprint!": "hello, fprint!",
		bytes.MinRead: "512",
		bytes.ErrTooLarge: "bytes.Buffer: too large",
	}

	for in, expected := range cases {
		buf := bytes.NewBuffer(nil)
		_, err := fmt.Fprint(buf, in)
		//assert.Nil(t, err)
		//assert.Equal(t, expected, buf.String())
		if err != nil {
			t.Errorf("fmt.Fprint: %s\n", err.Error())
		}

		actual := buf.String()

		if actual != expected {
			t.Errorf("\nExpected: %v\nActual: %v\n", expected, actual)
		}
	}
}
