package main

import (
	"log"
	"net/http"

	"github.com/gin-gonic/gin"
)

func HelloHandler(ctx *gin.Context) {
	ctx.JSON(http.StatusOK, gin.H{
		"Hello": "world from the go hw-gin-api example!",
	})
}

func main() {
	g := gin.Default()

	g.GET("/", HelloHandler)

	if err := g.Run("0.0.0.0:9001"); err != nil {
		log.Fatalf("Failed to run gin server: %v", err)
	}
}
