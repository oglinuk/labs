package path

import (
	"path"
	"testing"

	//"github.com/stretchr/testify/assert"
)

// TestPathExt ensures the expected file extensions are returned
func TestPathExt(t *testing.T) {
	cases := []struct {
		in, expected string
	}{
		{"hello.txt", ".txt"},
		{"books.csv", ".csv"},
		{"payload.json", ".json"},
		{"docker-compose.yml", ".yml"},
	}

	for _, c := range cases {
		actual := path.Ext(c.in)
		//assert.Equal(t, c.expected, actual)
		if actual != c.expected {
			t.Errorf("\nExpected: %v\n  Actual: %v\n", c.expected, actual)
		}
	}
}
