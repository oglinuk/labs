package os

import (
	"fmt"
	"os"
	"testing"

	//"github.com/stretchr/testify/assert"
)

const testDir = "testdata"

// TestReadDir ensures the expected paths are returned
func TestReadDir(t *testing.T) {
	expected := []string{
		"testdata/lorem-ipsum.txt",
		"testdata/os.html",
	}

	dirs, err := os.ReadDir(testDir)
	//assert.Nil(t, err)
	if err != nil {
		t.Error(err.Error())
	}

	for i, d := range dirs {
		//assert.Equal(t, expected[i], d.Name())
		actual := fmt.Sprintf("%s/%s", testDir, d.Name())
		if actual != expected[i] {
			t.Errorf("\nExpected: %v\n  Actual: %v\n", expected[i], actual)
		}
	}
}
