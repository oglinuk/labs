# bufio

"Package bufio implements buffered I/O. It wraps an io.Reader or
io.Writer object, creating another object (Reader or Writer) that also
implements the interface but provides buffering and some help for textual
I/O."

* [ ] constants
	* [ ] MaxScanTokenSize
* [ ] variables
	* [ ] ErrInvalidUnreadByte
	* [ ] ErrInvalidUnreadRune
	* [ ] ErrBufferFull
	* [ ] ErrNegativeCount
	* [ ] ErrTooLog
	* [ ] ErrNegativeAdvance
	* [ ] ErrAdvanceTooFar
	* [ ] ErrBadReadCount
	* [ ] ErrFinalToken
* [ ] functions
	* [ ] ScanBytes
	* [ ] ScanLines
	* [ ] ScanRunes
	* [ ] ScanWords
* [ ] types
	* [ ] ReadWriter
		* [ ] NewReadWriter
	* [ ] Reader
		* [ ] NewReader
		* [ ] NewReaderSize
		* [ ] Buffered
		* [ ] Discard
		* [ ] Peek
		* [ ] Read
		* [ ] ReadByte
		* [ ] ReadBytes
		* [ ] ReadLine
		* [ ] ReadRune
		* [ ] ReadSlice
		* [ ] ReadString
		* [ ] Reset
		* [ ] Size
		* [ ] UnreadByte
		* [ ] UnreadRune
		* [ ] WriteTo
	* [ ] Scanner
		* [X] NewScanner
		* [ ] Buffer
		* [ ] Bytes
		* [ ] Err
		* [X] Scan
		* [ ] Split
		* [X] Text
	* [ ] SplitFunc
	* [ ] Writer
		* [ ] NewWriter
		* [ ] NewWriterSize
		* [ ] Available
		* [ ] Buffered
		* [ ] Flush
		* [ ] ReadFrom
		* [ ] Reset
		* [ ] Size
		* [ ] Write
		* [ ] WriteByte
		* [ ] WriteRune
		* [ ] WriteString

Related:

* Package `bufio`
	<https://pkg.go.dev/bufio>

Tags:

	#lab #go #std #bufio
