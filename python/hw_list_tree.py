import os
import sys

def main(args):
    for root, dirs, files in os.walk(args[0]):
        for file in files:
            print('{}/{}'.format(root, file))

if __name__ == '__main__':
    main(sys.argv[1:])