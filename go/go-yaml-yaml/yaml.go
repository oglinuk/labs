package main

import (
	"fmt"
	"os"

	"gopkg.in/yaml.v2"
)

// GenerateYaml checks the filename and v inputs, marshals the given
// interface as yaml, creates a file called the given filename, and
// writes the yaml data to it
func GenerateYaml(filename string, v interface{}) error {
	if filename == "" {
		return fmt.Errorf("GenerateYaml::filename given was nil")
	}

	if v == nil {
		return fmt.Errorf("GenerateYaml::interface given was nil")
	}

	data, err := yaml.Marshal(v)
	if err != nil {
		return err
	}

	f, err := os.Create(filename)
	if err != nil {
		return err
	}
	defer f.Close()

	f.Write(data)

	return nil
}
