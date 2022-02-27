package main

import (
	"os"
	"testing"

	"github.com/stretchr/testify/assert"
)

// TestDompressBz2 ensures that the expected decompressed file exists, and
// contains expected content
func TestDompressBz2(t *testing.T) {
	expectedFile := "testdata/bzipped-lorem-ipsum.txt"

	err := decompressBz2("testdata/bzipped-lorem-ipsum.txt.bz2")
	assert.Nil(t, err)

	expectedBytes, err := os.ReadFile("testdata/lorem-ipsum.txt")
	assert.Nil(t, err)

	actualBytes, err := os.ReadFile(expectedFile)
	assert.Nil(t, err)
	assert.Equal(t, string(expectedBytes), string(actualBytes))
}
