import time
import subprocess

# Func for executing processes
def processCommunication(prSubprocess):
    # https://stackoverflow.com/a/3503909
    _proc = subprocess.Popen(['%s' % (prSubprocess)], stdout=subprocess.PIPE, shell=True)
    exe_proc = _proc.communicate()
    return exe_proc

# Func that takes user input for the time of break -> sleeps for n amount of time and prints a countdown
# When the countdown reaches 0 the SOS.mp3 song is played -> can be anything just rename the file to SOS.mp3
def timeForBreak():
    nTime = int(input('1) 15 min\n2) 30 min\n3) 45 min\n4) 1 hour\n\n'))

    breakTime = None
    if nTime == 1:
        breakTime = 900
    elif nTime == 2:
        breakTime = 1800
    elif nTime == 3:
        breakTime = 2700
    else:
        breakTime = 3600

    # Countdown
    for i in range(breakTime-1, 0, -1):
        print(i)
        time.sleep(1)
    processCommunication('SOS.mp3')

def main():
    timeForBreak()

if __name__ == '__main__':
    main()
