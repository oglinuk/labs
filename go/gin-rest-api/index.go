package main

import (
	"net/http"

	"github.com/gin-gonic/gin"
)

// IndexHandler returns a 200 and {"hello": "gin-rest-api example!"}
func IndexHandler(ctx *gin.Context) {
	ctx.JSON(http.StatusOK, gin.H{
		"hello": "gin-rest-api example!",
	})
}
