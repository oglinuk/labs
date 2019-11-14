package main

import (
	"database/sql"
	"fmt"

	_ "github.com/mattn/go-sqlite3"
)

// Source: https://www.thepolyglotdeveloper.com/2017/04/using-sqlite-database-golang-application/
func main() {
	database, _ := sql.Open("sqlite3", "./hw_sqlite.db")
	statement, _ := database.Prepare("CREATE TABLE IF NOT EXISTS world (id INTEGER PRIMARY KEY, name TEXT, message TEXT)")
	statement.Exec()
	statement, _ = database.Prepare("INSERT INTO world (name, message) VALUES (?, ?)")
	statement.Exec("hello", "from hw_sqlite!")
	rows, _ := database.Query("SELECT id, name, message FROM world")
	var id int
	var name string
	var message string
	for rows.Next() {
		rows.Scan(&id, &name, &message)
		fmt.Printf("[%d] %s %s\n", id, name, message)
	}
}
