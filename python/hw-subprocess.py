import time
import subprocess

def process_communication(process):
    # https://stackoverflow.com/a/3503909
    return subprocess.Popen(['%s' % (process)], stdout=subprocess.PIPE, shell=True).communicate()

if __name__ == '__main__':
    # countdown
    for i in range(7-1, 0, -1):
        print(i)
        time.sleep(1)
    process_communication('firefox')
