package main

import (
	"net/http"
	"net/http/httptest"
	"testing"

	"github.com/stretchr/testify/assert"
)

// TestIndexHandler ensures the handler returns the expected status code
func TestIndexHandler(t *testing.T) {
	r := newRouter()
	rr := httptest.NewRecorder()
	req := httptest.NewRequest("GET", "/", nil)

	r.ServeHTTP(rr, req)
	resp := rr.Result()
	assert.Equal(t, http.StatusOK, resp.StatusCode)
}
