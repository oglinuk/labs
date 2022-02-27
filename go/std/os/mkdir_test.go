package os

import (
	"os"
	"testing"

	//"github.com/stretchr/testify/assert"
)

const testMkdir = "testdata/testMkdir"

// TestOSMkdir ensures the expected directory is created successfully
func TestOSMkdir(t *testing.T) {
	err := os.Mkdir(testMkdir, 0744)
	//assert.Nil(t, err)
	if err != nil {
		t.Error(err.Error())
	}

	_, err = os.Stat(testMkdir)
	//assert.Nil(t, err)
	if err != nil {
		t.Error(err.Error())
	}

	t.Cleanup(func() {
		os.RemoveAll(testMkdir)
	})
}
