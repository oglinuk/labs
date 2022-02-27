package http

import (
	"fmt"
	"net/http"
	"net/http/httptest"
	"testing"

	//"github.com/stretchr/testify/assert"
)

// testHandler is a valid http.HandlerFunc used for testing
func testHandler(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintln(w, "hello, http!")
}

// TestHTTPGet ensures the response to a valid IP address is as expected
func TestHTTPGet(t *testing.T) {
	ts := httptest.NewServer(http.HandlerFunc(testHandler))
	defer ts.Close()

	resp, err := http.Get(ts.URL)
	//assert.Nil(t, err)
	//assert.Equal(t, http.StatusOK, resp.StatusCode)

	if err != nil {
		t.Error(err.Error())
	}

	expected := http.StatusOK
	actual := resp.StatusCode
	if actual != expected {
		t.Errorf("\nExpected: %v\n  Actual: %v\n", expected, actual)
	}
}
