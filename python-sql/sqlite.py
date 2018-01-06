'''
SQlite practice
'''

import sqlite3
from datetime import datetime
import os

def insertStatement(prDB, prCursor):
    _name = input('Name: ')
    prCursor.execute('''
        INSERT INTO tblPractice(datetimestamp, name) VALUES(?, ?)
    ''', (datetime.now(), _name))
    prDB.commit()
    print('Statement inserted...')

def selectAllStatement(prDB, prCursor):
    prCursor.execute('''
        SELECT * FROM tblPractice
    ''')
    for row in prCursor:
        print('%s : %s : %s' % (row[0], row[1], row[2]))

def createDB(prDB, prCursor):

    prCursor.execute('''
        CREATE TABLE tblPractice(id INTEGER PRIMARY KEY, datetimestamp TEXT, name TEXT)
    ''')
    prDB.commit()
    print('Successfully created the DB...')

def main():
    if not os.path.exists('sqlite3practice'):
        print('DB not found, creating one now...')
        db = sqlite3.connect('sqlite3practice')
        cursor = db.cursor()
        createDB(db, cursor)
    instanciate_new_db = input('SQLite DB found, would you like to create a new one? [Y/N]\n\n')
    if instanciate_new_db == 'Y' or instanciate_new_db == 'y':
        createDB(db, cursor)
    elif instanciate_new_db == 'N' or instanciate_new_db == 'n':
        os.system('cls')
        db_menu_selection = int(input('1) Show DB entries\n2) Insert new entry\n\n'))
        if db_menu_selection == 1:
            os.system('cls')
            selectAllStatement(db, cursor)
        elif db_menu_selection == 2:
            os.system('cls')
            insertStatement(db, cursor)
        db.close()
    else:
        print('Invalid Input... Try Again Noob')
    main()

if __name__ == '__main__':
    main()
