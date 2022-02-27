package net

import (
	"net"
	"testing"

	//"github.com/stretchr/testify/assert"
)

// TestNetJoinHostPort ensures the expected strings are returned
func TestNetJoinHostPort(t *testing.T) {
	cases := map[string]testAddr{
		"127.0.0.1:8080": testAddr{"127.0.0.1", "8080"},
		"localhost:443": testAddr{"localhost", "443"},
		"192.168.42.7:69": testAddr{"192.168.42.7", "69"},
		"[::1]:443": testAddr{"::1", "443"},
		"[0000:0000:0000:0000]:9001": testAddr{
			"0000:0000:0000:0000", "9001",
		},
	}

	for expected, addr := range cases {
		actual := net.JoinHostPort(addr.Host, addr.Port)
		//assert.Equal(t, expected[i], actual)
		if actual != expected {
			t.Errorf("\nExpected: %v\n  Actual: %v\n", expected, actual)
		}
	}
}
