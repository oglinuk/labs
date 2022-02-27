# os

"Package os provides a platform-independent interface to operating system
functionality. The design is Unix-like, although the error handling is
Go-like; failing calls return values of type error rather than error
numbers. Often, more information is available within the error. For
example, if a call that takes a file name fails, such as Open or Stat,
the error will include the failing file name when printed and will be of
type \*PathError, which may be unpacked for more information.

The os interface is intended to be uniform across all operating systems.
Features not generally available appear in the system-specific package
syscall."

* [ ] constants
	* [ ] O_RDONLY
	* [ ] O_WRONLY
	* [ ] O_RDWR
	* [ ] O_APPEND
	* [ ] O_CREATE
	* [ ] O_EXCL
	* [ ] O_SYNC
	* [ ] O_TRUNC
	* [ ] SEEK_SET
	* [ ] SEEK_CUR
	* [ ] SEEK_END
	* [ ] PathSeparator
	* [ ] PathListSeparator
	* [ ] ModeDir
	* [ ] ModeAppend
	* [ ] ModeExclusive
	* [ ] ModeTemporary
	* [ ] ModeSymlink
	* [ ] ModeDevice
	* [ ] ModeNamedPipe
	* [ ] ModeSocket
	* [ ] ModeSetuid
	* [ ] ModeSetgid
	* [ ] ModeCharDevice
	* [ ] ModeSticky
	* [ ] ModeIrregular
	* [ ] ModeType
	* [ ] ModePerm
	* [ ] DevNull
* [ ] variables
	* [ ] ErrInvalid
	* [ ] ErrPermission
	* [ ] ErrExist
	* [ ] ErrNotExist
	* [ ] ErrClosed
	* [ ] ErrNoDeadline
	* [ ] ErrDeadlineExceeded
	* [ ] Stdin
	* [ ] Stdout
	* [ ] Stderr
	* [ ] Args
	* [ ] ErrProcessDone
* [ ] functions
	* [ ] Chdir
	* [ ] Chmod
	* [ ] Chown
	* [ ] Chtimes
	* [ ] Clearenv
	* [ ] DirFS
	* [ ] Environ
	* [ ] Executable
	* [ ] Exit
	* [ ] Expand
	* [ ] ExpandEnv
	* [ ] Getegid
	* [ ] Getenv
	* [ ] Geteuid
	* [ ] Getgid
	* [ ] Getgroups
	* [ ] Getpagesize
	* [ ] Getpid
	* [ ] Getppid
	* [ ] Getuid
	* [ ] Getwd
	* [ ] Hostname
	* [ ] IsExist
	* [ ] IsNotExist
	* [ ] IsPathSeparator
	* [ ] IsPermission
	* [ ] IsTimeout
	* [ ] Lchown
	* [ ] Link
	* [ ] LookupEnv
	* [X] Mkdir
	* [ ] MkdirAll
	* [ ] MkdirTemp
	* [ ] NewSyscallError
	* [ ] Pipe
	* [ ] ReadFile
	* [ ] Readlink
	* [ ] Remove
	* [ ] RemoveAll
	* [ ] Rename
	* [ ] SameFile
	* [ ] Setenv
	* [ ] Symlink
	* [ ] TempDir
	* [ ] Truncate
	* [ ] Unsetenv
	* [ ] UserCacheDir
	* [ ] UserConfigDir
	* [ ] UserHomeDir
	* [ ] WriteFile
* [ ] types
	* [ ] DirEntry
		* [ ] Create
		* [ ] CreateTemp
		* [ ] NewFile
		* [ ] Open
		* [ ] OpenFile
		* [ ] Chdir
		* [ ] Chmod
		* [ ] Chown
		* [ ] Close
		* [ ] Fd
		* [ ] Name
		* [ ] Read
		* [ ] ReadAt
		* [X] ReadDir
		* [ ] ReadFrom
		* [ ] Readdir
		* [ ] Readdirnames
		* [ ] Seek
		* [ ] SetDeadline
		* [ ] SetReadDeadline
		* [ ] SetWriteDeadline
		* [ ] Stat
		* [ ] Sync
		* [ ] SyscallConn
		* [ ] Truncate
		* [ ] Write
		* [ ] WriteAt
		* [ ] WriteString
	* [ ] FileInfo
		* [ ] Lstat
		* [ ] Stat
	* [ ] FileMode
	* [ ] LinkError
		* [ ] Error
		* [ ] Unwrap
	* [ ] PathError
	* [ ] ProcAttr
	* [ ] Process
		* [ ] FindProcess
		* [ ]	StartProcess
		* [ ] Kill
		* [ ] Release
		* [ ] Signal
		* [ ] Wait
	* [ ] ProcessState
		* [ ] ExitCode
		* [ ] Exited
		* [ ] Pid
		* [ ] String
		* [ ] Success
		* [ ] Sys
		* [ ] SysUsage
		* [ ] SystemTime
		* [ ] UserTime
	* [ ] Signal
	* [ ] SyscallError
		* [ ] Error
		* [ ] Timeout
		* [ ] Unwrap

Related:

* Package `os`
	<https://pkg.go.dev/os>

Tags:

	#lab #go #std #os
