package main

import (
	"io"
	"os"
	"testing"

	"github.com/stretchr/testify/assert"
)

const testfile = "generated.yaml"

// TestGenerateYaml ensures the generated yaml file is as expected
func TestGenerateYaml(t *testing.T) {
	expected := `hello: world!
`

	err := GenerateYaml(testfile, map[string]interface{}{
		"hello": "world!",
	})
	assert.Nil(t, err)

	f, err := os.Open(testfile)
	assert.Nil(t, err)
	defer f.Close()

	b, err := io.ReadAll(f)
	assert.Nil(t, err)
	assert.Equal(t, expected, string(b))
}
