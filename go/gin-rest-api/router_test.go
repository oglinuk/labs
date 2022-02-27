package main

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

// TestNewRouter ensures the router returned is not nil
func TestNewRouter(t *testing.T) {
	assert.NotNil(t, newRouter())
}
