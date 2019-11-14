package main

import (
	"encoding/json"
	"fmt"
	"os"
)

const (
	jsonName = "gopher.json"
)

type Gopher struct {
	Name string
	Age  int
}

func main() {
	g, err := loadJSON()
	if err != nil {
		main()
	} else {
		fmt.Println(g)
	}
}

func saveJSON(g *Gopher) error {
	f, err := os.Create(jsonName)
	if err != nil {
		return err
	}
	defer f.Close()

	encoder := json.NewEncoder(f)
	encoder.SetIndent("", "\t")
	encoder.Encode(g)

	return nil
}

func loadJSON() (Gopher, error) {
	var g Gopher
	f, err := os.Open(jsonName)
	if err != nil {
		saveJSON(&Gopher{
			Name: "bob",
			Age:  42,
		})
		return g, err
	}
	defer f.Close()

	decoder := json.NewDecoder(f)
	err = decoder.Decode(&g)

	return g, err
}
