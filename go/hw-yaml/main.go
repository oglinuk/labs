package main

import (
	"fmt"
	"os"

	"gopkg.in/yaml.v2"
)

type dockerservice struct {
	Hostname string
	ContainerName string `yaml:"container_name"`
	Image string
	Ports []string
}

type dockercompose struct {
	Version string
	Services map[string]dockerservice
}

var (
	example = `version: "3"
services:
  hello-world:
    hostname: hello-world
    container_name: hello-world-container
    image: hello-world`
)

func main() {
	dc := dockercompose{}

	err := yaml.Unmarshal([]byte(example), &dc)
	if err != nil {
		panic(err)
	}

	fmt.Printf("%v\n\n", dc)

	dc.Services["nginx"] = dockerservice{
		Hostname: "nginx",
		ContainerName: "nginx-container",
		Image: "nginx",
		Ports: []string{"80:80"},
	}

	bytes, err := yaml.Marshal(&dc)
	if err != nil {
		panic(err)
	}

	f, err := os.Create("docker-compose.yml")
	if err != nil {
		panic(err)
	}
	defer f.Close()

	f.Write(bytes)
}
