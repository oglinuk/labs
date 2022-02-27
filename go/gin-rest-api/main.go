package main

import (
	"log"

	"github.com/gin-gonic/gin"
)

func main() {
	g := gin.Default()

	g.GET("/", IndexHandler)

	log.Fatal(g.Run(":9001"))
}
