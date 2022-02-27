package sha256

import (
	"testing"

	//"github.com/stretchr/testify/assert"
)

// TestGenerateHash ensures the expected SHA256 hash is returned
func TestGenerateSHA256Hash(t *testing.T) {
	expected := `68e656b251e67e8358bef8483ab0d51c6619f3e7a1a9f0e75838d41ff368f728`
	actual := GenerateHash("hello, world!")
	//assert.Equal(t, expected, actual)
	if actual != expected {
		t.Errorf("\nExpected: %v\n  Actual: %v\n", expected, actual)
	}
}
