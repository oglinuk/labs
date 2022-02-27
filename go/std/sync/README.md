# sync

"Package sync provides basic synchronization primitives such as mutual
exclusion locks. Other than the Once and WaitGroup types, most are
intended for use by low-level library routines. Higher-level
synchronization is better done via channels and communication.

Values containing the types defined in this package should not be
copied."

* [ ] types
	* [ ] Cond
		* [ ] NewCond
		* [ ] Broadcast
		* [ ] Signal
		* [ ] Wait
	* [ ] Locker
	* [ ] Map
		* [ ] Delete
		* [ ] Load
		* [ ] LoadAndDelete
		* [ ] LoadOrStore
		* [ ] Range
		* [ ] Store
	* [ ] Mutex
		* [ ] Lock
		* [ ] Unlock
	* [ ] Once
		* [ ] Do
	* [ ] Pool
		* [ ] Get
		* [ ] Put
	* [ ] RWMutex
		* [ ] Lock
		* [ ] RLock
		* [ ] RLocker
		* [ ] RUnlock
		* [ ] Unlock
	* [ ] WaitGroup
		* [X] Add
		* [ ] Done
		* [ ] Wait

Related:

* Package `sync`
	<https://pkg.go.dev/sync>

Tags:

	#lab #go #std #sync
