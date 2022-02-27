package json

import (
	"testing"

	//"github.com/stretchr/testify/assert"
)

// TestEncodeToString ensures valid JSON is encoded as expected
func TestEncodeToString(t *testing.T) {
	expected := `{"hello":"world!"}`
	actual, err := EncodeToString(map[string]string{"hello":"world!"})
	//assert.Nil(t, err)
	//assert.Equal(t, expected, actual)
	if err != nil {
		t.Error(err.Error())
	}

	if actual != expected {
		t.Errorf("\nExpected: %v\n  Actual: %v\n", expected, actual)
	}
}
