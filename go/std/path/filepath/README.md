# filepath

"Package filepath implements utility routines for manipulating filename
paths in a way compatible with the target operating system-defined file
paths.

The filepath package uses either forward slashes or backslashes,
depending on the operating system. To process paths such as URLs that
always use forward slashes regardless of the operating system, see the
path package."

* [ ] constants
	* [ ] Separator
	* [ ] ListSeparator
* [ ] variables
	* [ ] ErrBadPattern
	* [ ] SkipDir
* [ ] functions
	* [ ] Abs
	* [ ] Base
	* [ ] Clean
	* [ ] Dir
	* [ ] EvalSymlinks
	* [ ] Ext
	* [ ] FromSlash
	* [ ] Glob
	* [ ] IsAbs
	* [ ] Join
	* [ ] Match
	* [ ] Rel
	* [ ] Split
	* [ ] SplitList
	* [ ] ToSlash
	* [ ] VolumeName
	* [ ] Walk
	* [ ] WalkDir
* [ ] types
	* [ ] WalkFunc

Related:

* Package `filepath`
	<https://pkg.go.dev/path/filepath>

Tags:

	#lab #go #std #filepath
