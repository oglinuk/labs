# path

"Package path implements utility routines for manipulating
slash-separated paths.

The path package should only be used for paths separated by forward
slashes, such as the paths in URLs. This package does not deal with
Windows paths with drive letters or backslashes; to manipulate operating
system paths, use the path/filepath package."

* [ ] variables
	* [ ] ErrBadPattern
* [ ] functions
	* [ ] Base
	* [ ] Clean
	* [ ] Dir
	* [X] Ext
	* [ ] IsAbs
	* [ ] Join
	* [ ] Match
	* [ ] Split

Related:

* Package `path`
	<https://pkg.go.dev/path>

Tags:

	#lab #go #std #path
