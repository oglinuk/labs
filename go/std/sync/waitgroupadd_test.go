package sync

import (
	"reflect"
	"sync"
	"testing"

	//"github.com/stretchr/testify/assert"
)

// TestWaitGroupAdd ensures the sync.WaitGroup is at the expected counter
func TestWaitGroupAdd(t *testing.T) {
	inputs := []int{42, 7, 69, 1729, 1000000001}
	expected := []uint64{
		0x2a, // 42
		0x7, // 7
		0x45, // 69
		0x6c1, // 1729
		0x3b9aca01, // 1000000001
	}

	for i, in := range inputs {
		wg := &sync.WaitGroup{}
		wg.Add(in)

		v := reflect.ValueOf(wg).Elem().FieldByName("state1")
		actual := v.Index(1).Uint()
		//assert.Equal(t, expected[i], actual)
		if actual != expected[i] {
			t.Errorf("\nExpected: %v\n  Actual: %v\n", expected[i], actual)
		}
	}
}
