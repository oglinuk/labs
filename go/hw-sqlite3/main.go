package main

import (
	"context"
	"database/sql"
	"fmt"
	"os"

	_ "github.com/mattn/go-sqlite3"
)

var (
	db  *sql.DB
	err error
	ctx context.Context

	dbname = "./test.db"
)

func insert(name string) {
	_, err = db.Exec(`INSERT INTO tblUser(name) VALUES(?)`, name)
	if err != nil {
		panic(err)
	}
}

func initDatabase() {
	_, err = db.Exec(`
		CREATE TABLE tblUser(
 			id INTEGER PRIMARY KEY AUTOINCREMENT,
 			name TEXT
		);`)
	if err != nil {
		panic(err)
	}
}

func main() {
	if _, err = os.Stat(dbname); err == nil {
		os.Remove(dbname)
	}

	db, err = sql.Open("sqlite3", dbname)
	if err != nil {
		panic(err)
	}
	defer db.Close()

	initDatabase()

	insert("Bob")
	insert("Alice")

	row, err := db.Query(`SELECT * FROM tblUser`)
	if err != nil {
		panic(err)
	}
	defer row.Close()

	for row.Next() {
		var id int
		var name string
		if err = row.Scan(&id, &name); err != nil {
			panic(err)
		}
		fmt.Printf("User(%d): %s\n", id, name)
	}
}
