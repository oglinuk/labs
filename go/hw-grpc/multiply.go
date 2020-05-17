package main

import (
	"net/http"
	"strconv"

	mpb "./proto"
	"github.com/gin-gonic/gin"
)

func MultiplyHandler(ctx *gin.Context) {
	a, err := strconv.ParseUint(ctx.Param("a"), 10, 64)
	if err != nil {
		ctx.JSON(http.StatusBadRequest, gin.H{"error": "Invalid A Parameter"})
		return
	}

	b, err := strconv.ParseUint(ctx.Param("b"), 10, 64)
	if err != nil {
		ctx.JSON(http.StatusBadRequest, gin.H{"error": "Invalid A Parameter"})
		return
	}

	req := &mpb.MultiplyRequest{A: a, B: b}

	if resp, err := c.Multiply(ctx, req); err == nil {
		ctx.JSON(http.StatusOK, gin.H{
			"N": resp.N,
		})
	} else {
		ctx.JSON(http.StatusInternalServerError, gin.H{"error": err})
	}
}
