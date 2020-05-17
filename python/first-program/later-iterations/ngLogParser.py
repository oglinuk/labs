'''
ngLogParser.py - 6/3/2017
'''

import csv

def main():
    with open('c:\\logs\\RAWnglogs.txt', 'r') as nglIN, open('c:\\logs\\ngpLogs.csv', 'ab+') as ngplOUT:
        i = 0
        rowCount = 10 #len(nglIN)
        while (i < rowCount):
            rowCount += 1
            for line in nglIN:
                rowCount += 1
                logs = line.split(':')
                #print(logs)
                log_date = logs[0]
                log_origin = logs[3]
                log_level = logs[4]
                log_info = logs[5]
                log_input = logs[6]
                #logEntry = [log_date, log_origin, log_level, log_info, log_input]
                #logRow = '%s %s %s %s %s' % (log_date, log_origin, log_level, log_info, log_input)
                ngplOUT.write(bytes(log_date, 'UTF-8'))
                ngplOUT.write(bytes(log_origin, 'UTF-8'))
                ngplOUT.write(bytes(log_level, 'UTF-8'))
                ngplOUT.write(bytes(log_info, 'UTF-8'))
                ngplOUT.write(bytes(log_input, 'UTF-8'))
                '''
                for log in logs[0:8]:
                    logz = log.split(' ')
                    for logEntry in logz[0:8]:
                        ngplOUT.write(bytes(logEntry, 'UTF-8'))
                '''

if (__name__ == '__main__'):
    main()
