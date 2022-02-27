package net

import (
	"net"
	"testing"

	//"github.com/stretchr/testify/assert"
)

// TestNetSplitHostPort ensures the expected strings are returned
func TestNetSplitHostPort(t *testing.T) {
	cases := map[string]testAddr{
		"127.0.0.1:8080": testAddr{"127.0.0.1", "8080"},
		"localhost:443": testAddr{"localhost", "443"},
		"192.168.42.7:69": testAddr{"192.168.42.7", "69"},
		"[::1]:443": testAddr{"::1", "443"},
		"[0000:0000:0000:0000]:9001": testAddr{
			"0000:0000:0000:0000", "9001",
		},
	}


	for addr, expected := range cases {
		actHost, actPort, err := net.SplitHostPort(addr)
		//assert.Nil(t, err)
		//assert.Equal(t, expected.Host, actHost)
		//assert.Equal(t, expected.Port, actPort)

		if err != nil {
			t.Error(err.Error())
		}

		if actHost != expected.Host {
			t.Errorf("\nExpected: %v\n  Actual: %v\n", expected.Host, actHost)
		}

		if actPort != expected.Port {
			t.Errorf("\nExpected: %v\n  Actual: %v\n", expected.Port, actPort)
		}
	}
}
