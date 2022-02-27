package filepath

import (
	"io/fs"
	"path/filepath"
	"testing"

	//"github.com/stretchr/testify/assert"
)

const testDir = "testdata"

// TestFilepathWalk ensures the expected paths are found when walking
func TestFilepathWalk(t *testing.T) {
	expected := []string{
		"testdata",
		"testdata/lorem-ipsum.txt",
		"testdata/nested",
		"testdata/nested/another",
		"testdata/nested/another/file.md",
		"testdata/nested/hello.txt",
	}

	i := 0
	walker := func(path string, info fs.FileInfo, err error) error {
		if err != nil {
			return err
		}

		//assert.Equal(t, expected[i], path)
		if path != expected[i] {
			t.Errorf("\nExpected: %v\n  Actual: %v\n", expected[i], path)
		}
		i++

		return nil
	}

	err := filepath.Walk(testDir, walker)
	//assert.Nil(t, err)
	if err != nil {
		t.Error(err.Error())
	}
}
