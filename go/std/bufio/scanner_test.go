package bufio

import (
	"bufio"
	"os"
	"testing"

	//"github.com/stretchr/testify/assert"
)

// TestBufioScanner ensures when scanning a given file, the resulting
// tokens are as expected
func TestBufioScanner(t *testing.T) {
	expected := []string{
		"Lorem ipsum dolor sit amet, consectetur adipiscing elit. In quis",
		"facilisis lacus. Pellentesque pharetra mollis ante, et accumsan nunc",
		"fringilla at. Integer vel interdum libero, ut pulvinar mauris. Aliquam",
		"erat volutpat. Pellentesque tempus libero purus, ut iaculis elit",
		"scelerisque vel. Proin fringilla nisl vitae cursus lobortis. Nulla",
		"facilisi. Donec accumsan nibh et ex gravida, vehicula imperdiet enim",
		"aliquet.",
	}

	f, err := os.Open("testdata/lorem-ipsum.txt")
	//assert.Nil(t, err)
	if err != nil {
		t.Error(err.Error())
	}
	defer f.Close()

	bs := bufio.NewScanner(f)

	i := 0
	for bs.Scan() {
		// assert.Equal(t, expected[i], bs.Text())
		actual := bs.Text()
		if actual != expected[i] {
			t.Errorf("\nExpected: %v\n  Actual: %v\n", expected, actual)
		}
		i++
	}
}
