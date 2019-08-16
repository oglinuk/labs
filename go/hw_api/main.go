package main

import (
	"crypto/tls"
	"fmt"
	"io/ioutil"
	"net/http"
)

func main() {
	URL := "https://api.ipify.org?format=json"

	if err := execute(URL); err != nil {
		panic(err)
	}
}

func execute(s string) error {
	client := http.Client{
		Transport: &http.Transport{
			TLSClientConfig: &tls.Config{
				InsecureSkipVerify: true,
			},
		},
	}

	resp, err := client.Get(s)
	if err != nil {
		return err
	}

	if resp == nil {
		return err
	}

	if resp.StatusCode >= 200 && resp.StatusCode < 300 {
		out, err := ioutil.ReadAll(resp.Body)
		if err != nil {
			return err
		}
		fmt.Println(string(out))
	} else {
		return err
	}

	return nil
}
