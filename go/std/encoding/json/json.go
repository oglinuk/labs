package json

import (
	"encoding/json"
	"fmt"
)

// EncodeToString marshals the given interface as JSON and returns the
// string representation
func EncodeToString(v interface{}) (string, error) {
	if v == nil {
		return "", fmt.Errorf("json::Encode: given interface is nil")
	}

	b, err := json.Marshal(v)
	if err != nil {
		return "", err
	}

	return string(b), nil
}
