package net

import (
	"net"
	"testing"

	//"github.com/stretchr/testify/assert"
)

// gotta show IPv6 some love
const testIP = "[::1]:22"

// TestNetDial ensures that dialing the SSH daemon is as expected
func TestNetDial(t *testing.T) {
	conn, err := net.Dial("tcp", testIP)
	if err != nil {
		t.Error(err.Error())
	}
	defer conn.Close()

	// assert.Equal(t, testIP, conn.RemoteAddr().String())
	actualRemoteAddr := conn.RemoteAddr().String()
	if actualRemoteAddr != testIP {
		t.Errorf("\nExpected: %v\n  Actual: %v\n", testIP, actualRemoteAddr)
	}
}
