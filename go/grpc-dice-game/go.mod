module github.com/oglinuk/labs/go/grpc-dice-game

go 1.17

require (
	github.com/golang/protobuf v1.5.2
	golang.org/x/net v0.0.0-20220127200216-cd36cc0744dd
	google.golang.org/grpc v1.44.0
)

require (
	golang.org/x/sys v0.0.0-20211216021012-1d35b9e2eb4e // indirect
	golang.org/x/text v0.3.7 // indirect
	google.golang.org/genproto v0.0.0-20200526211855-cb27e3aa2013 // indirect
	google.golang.org/protobuf v1.26.0 // indirect
)

replace github.com/oglinuk/labs/go/grpc-dice-game/proto => ./proto
