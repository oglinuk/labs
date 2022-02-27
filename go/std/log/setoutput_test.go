package main

import (
	"log"
	"os"
	"testing"

	//"github.com/stretchr/testify/assert"
)

const logf = "setoutput.log"

// TestLogSetOutput ensures that a valid file handler is written to when
// logging, after using as argument for log.SetOutput
func TestLogSetOutput(t *testing.T) {
	f, err := os.Create(logf)
	//assert.Nil(t, err)
	if err != nil {
		t.Error(err.Error())
	}

	log.SetOutput(f)

	log.Println("hello, setoutput.log!")

	f.Close()

	actual, err := os.ReadFile(logf)
	//assert.Nil(t, err)
	if err != nil {
		t.Error(err.Error())
	}

	//assert.NotEqual(t, 0, len(actual))
	if len(actual) == 0 {
		t.Errorf("%s contains nothing ...\n", logf)
	}
}
