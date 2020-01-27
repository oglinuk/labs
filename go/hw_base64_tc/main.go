package main

import (
	"crypto/tls"
	"encoding/base64"
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
	"os"
	"time"

	"github.com/gin-gonic/gin"
)

var (
	cntr            = 0
	fname           = "hwbase64.logs"
	f               *os.File
	sBase64HandlerT time.Time
	err             error
)

//
func invokeAPI() {
	// Delay by 2 seconds to allow for web server to start
	time.Sleep(time.Second * 2)

	client := http.Client{
		Transport: &http.Transport{
			TLSClientConfig: &tls.Config{
				InsecureSkipVerify: true,
			},
		},
	}

	resp, err := client.Get("http://localhost:9001")
	if err != nil {
		log.Printf("main.go:::invokeAPI::client.Get::ERROR: %s", err.Error())
	}

	if resp == nil {
		log.Println("main.go:::invokeAPI::resp::NIL ...")
	}

	if resp.StatusCode >= 200 && resp.StatusCode < 300 {
		out, err := ioutil.ReadAll(resp.Body)
		if err != nil {
			log.Printf("main.go:::invokeAPI::ioutil.ReadAll::ERROR: %s", err.Error())
		}
		fmt.Println(string(out))
	} else {
		log.Printf("main.go:::invokeAPI::resp.StatusCode::NOT_GOOD: %s", err.Error())
	}
}

func hwBase64Handler(ctx *gin.Context) {
	sBase64HandlerT = time.Now()

	fbytes, err := ioutil.ReadFile(fname)
	if err != nil {
		log.Printf("main.go::hwBase64Handler::os.Open::ERROR: %s", err.Error())
	}

	stats, err := os.Stat(fname)
	if err != nil {
		panic(err)
	}

	b64 := base64.StdEncoding.EncodeToString(fbytes)
	fsize := stats.Size()
	tc := fmt.Sprintf("%s", time.Since(sBase64HandlerT))

	log.Printf("[%d] %s | size: %d | tc: %s ...", cntr, fname, fsize, tc)

	ctx.JSON(http.StatusOK, gin.H{
		"base64":          b64,
		"size":            fsize,
		"time complexity": tc,
		"iteration":       cntr,
	})
	cntr++
}

func init() {
	f, err = os.OpenFile("hwbase64.logs", os.O_APPEND|os.O_WRONLY|os.O_CREATE, 0777)
	if err != nil {
		log.Printf("main.go::init::os.OpenFile::ERROR: %s", err.Error())
	}

	//defer f.Close()

	log.SetOutput(f)

	log.Println("Successfully initialized the logger ...")
}

func main() {
	defer log.Println("API is running ...")

	log.Println("Defering API requests ...")
	for i := 0; i < 100; i++ {
		go func() {
			for j := 0; j < 10; j++ {
				defer invokeAPI()
			}
		}()
	}

	defer log.Println("Finished API requests ...")

	r := gin.Default()
	r.GET("/", hwBase64Handler)

	if err := r.Run(":9001"); err != nil {
		log.Fatalf("main.go::r.Run::ERROR: %s", err.Error())
	}
}
