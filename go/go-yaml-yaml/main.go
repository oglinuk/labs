package main

import (
	"log"
	"fmt"
	"os"

	"gopkg.in/yaml.v2"
)

const (
	dcFilename = "docker-compose.yml"
	example = `version: "3"
services:
  hello-world:
    hostname: hello-world
    container_name: hello-world-container
    image: hello-world
  redis:
    hostname: redis
    container_name: redis-container
    image: redis
    ports:
      - 6379:6379
    networks:
      - tiered

networks:
  tiered:`
)

type dockerservice struct {
	Hostname string `yaml:"hostname"`
	ContainerName string `yaml:"container_name"`
	Image string `yaml:"image"`
	Ports []string `yaml:"ports"`
}

type dockercompose struct {
	Version string
	Services map[string]dockerservice
	Networks map[string]interface{}
}


func main() {
	dc := &dockercompose{}

	err := yaml.Unmarshal([]byte(example), dc)
	if err != nil	{
		log.Fatalf("yaml.Unmarshal: %s\n", err.Error())
	}

	fmt.Printf("%v\n\n", dc)

	dc.Services["nginx"] = dockerservice{
		Hostname: "nginx",
		ContainerName: "nginx-container",
		Image: "nginx:latest",
		Ports: []string{"80:80"},
	}

	b, err := yaml.Marshal(&dc)
	if err != nil	{
		log.Fatalf("yaml.Marshal: %s\n", err.Error())
	}

	f, err := os.Create(dcFilename)
	if err != nil	{
		log.Fatalf("os.Create: %s\n", err.Error())
	}
	defer f.Close()

	f.Write(b)

	log.Println("Run `docker-compose up` ...")
}
