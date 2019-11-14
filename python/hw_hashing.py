import hashlib

def main():
    print(hashlib.sha256(b'helloworld').hexdigest())  # prints hash
    print(hashlib.sha256(b'helloworld').digest())     # prints ascii version

if __name__ == '__main__':
    main()
