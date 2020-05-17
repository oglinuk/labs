package main

import (
	"log"

	mpb "./proto"
	"github.com/gin-gonic/gin"
	"google.golang.org/grpc"
)

var (
	c mpb.MServiceClient
	g *gin.Engine
)

func init() {
	go initServer()
}

func main() {
	conn, err := grpc.Dial("localhost:10001", grpc.WithInsecure())
	if err != nil {
		log.Fatalf("Failed to dial grpc server: %v", err)
	}

	c = mpb.NewMServiceClient(conn)

	g = gin.Default()

	g.GET("/:a/:b", MultiplyHandler)

	log.Println("Goto localhost:9001/<number1>/<number2>")
	if err := g.Run("0.0.0.0:9001"); err != nil {
		log.Fatalf("Failed to run gin server: %v", err)
	}
}
