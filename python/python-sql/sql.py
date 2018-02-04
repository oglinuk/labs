'''
mySQL database connector

Problems:
    autocommit = False by default
'''

import pymysql
import pysqlconfig

def main():

    conn = pymysql.connect(host=pysqlconfig.host, user=pysqlconfig.user, password=pysqlconfig.password, db=pysqlconfig.db, autocommit=True)

    cur = conn.cursor()

    logfile_path = input('Please enter the filename:\n')
    with open('c:\\logs\\%s.txt' % (logfile_path), 'r') as logfileIN:

        for log in logfileIN.readlines():
            # log DateTime
            datetime = log[0:16]
            # log Name
            name = log[17:22]
            # log Level
            levelname = log[23:27]
            # log Priority
            value_priority = log[28:30]
            # log Value
            log_value = log[31:]
            print('%s %s %s %s %s' % (datetime, name, levelname, value_priority, log_value))
            cur.execute('INSERT INTO tblLogs(log_DateTime, log_Name, log_Level, log_ValueType, log_Value) VALUES(%s, %s, %s, %s, %s)',
                                            (datetime, name, levelname, value_priority, log_value))

if __name__ == '__main__':
    main()
