package main

import (
	"os"
	"testing"

	"github.com/stretchr/testify/assert"
)

// TestCompressBz2 ensures that the expected compressed file exists, and
// is the expected size
func TestCompressBz2(t *testing.T) {
	expectedFile := "testdata/lorem-ipsum.txt.bz2"
	expectedFilesize := int64(21999)

	err := compressBz2("testdata/lorem-ipsum.txt")
	assert.Nil(t, err)

	info, err := os.Stat(expectedFile)
	assert.Nil(t, err)
	assert.Equal(t, expectedFilesize, info.Size())
}
