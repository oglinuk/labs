import string

# This is a test around newlines and the str.join() method
def main():
    print('\n'.join([c for c in string.ascii_lowercase]))

if __name__ == '__main__':
    main()
