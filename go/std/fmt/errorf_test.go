package main

import (
	"fmt"
	"io"
	"io/fs"
	"os"
	"testing"
	"reflect"

	//"github.com/stretchr/testify/assert"
)

// errorfTestCase wraps a string and error to be used as input for
// fmt.Errorf tests
type errorfTestCase struct {
	Msg string
	Err error
}

// TestFmtErrof ensures the expected error is returned
func TestFmtErrorf(t *testing.T) {
	cases := map[errorfTestCase]error {
		errorfTestCase{
			Msg: "hello, EOF",
			Err: io.ErrUnexpectedEOF,
		}:fmt.Errorf("hello, EOF: unexpected EOF"),
		errorfTestCase{
			Msg: "hello, permission denied",
			Err: fs.ErrPermission,
		}:fmt.Errorf("hello, permission denied: permission denied"),
		errorfTestCase{
			Msg: "hello, file already closed",
			Err: os.ErrClosed,
		}:fmt.Errorf("hello, file already closed: file already closed"),
	}

	for tc, expected := range cases {
		actual := fmt.Errorf("%s: %s", tc.Msg, tc.Err)
		//assert.Equal(t, expected, actual)
		if !reflect.DeepEqual(actual, expected) {
			t.Errorf("\nExpected: %v\n  Actual: %v\n", expected, actual)
		}
	}
}
