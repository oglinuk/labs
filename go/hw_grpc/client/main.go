package main

import (
	"log"

	"github.com/gin-gonic/gin"
	mpb "gitlab.com/OGLinuk/mdas/proto/m"
	"google.golang.org/grpc"
)

var (
	Client mpb.MServiceClient
	g      *gin.Engine
)

func main() {
	conn, err := grpc.Dial("grpc-server:9001", grpc.WithInsecure())
	if err != nil {
		log.Fatalf("Failed to dial grpc server: %v", err)
	}

	Client = mpb.NewMServiceClient(conn)

	g = gin.Default()

	g.GET("/:a/:b", MultiplyHandler)

	log.Println("Goto localhost:9002/<number1>/<number2>")

	if err := g.Run("0.0.0.0:9002"); err != nil {
		log.Fatalf("Failed to run gin server: %v", err)
	}
}
