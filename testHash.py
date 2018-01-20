import hashlib

def main():
    print(hashlib.sha256(b'helloworld').hexdigest())  # returns digested hexicode
    print(hashlib.sha256(b'helloworld').digest())     # returns ascii codes

if __name__ == '__main__':
    main()
