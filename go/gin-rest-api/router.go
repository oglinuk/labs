package main

import "github.com/gin-gonic/gin"

// newRouter creates a gin.Engine, assigns the "/" route to the
// IndexHandler with the GET method, and returns the gin.Engine
func newRouter() *gin.Engine {
	r := gin.Default()
	r.GET("/", IndexHandler)

	return r
}
