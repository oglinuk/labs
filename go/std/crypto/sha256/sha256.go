package sha256

import (
	"crypto/sha256"
	"encoding/hex"
)

// GenerateHash creates a new sha256 hasher, writes the given
// plaintext to the hasher, then returns the string representation
func GenerateHash(plaintext string) string {
	h := sha256.New()
	h.Write([]byte(plaintext))
	return hex.EncodeToString(h.Sum(nil))
}
