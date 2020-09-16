from Crypto.Cipher import AES
from Crypto import Random
import sys

class AESEncryptor(object):
    def __init__(self, key):
        self.key = self.pad(key)

    # Padding for AES key so it conforms to the required 16, 24, or 32 bytes
    def pad(self, s):
        return s + (AES.block_size - len(s) % AES.block_size) * chr(AES.block_size - len(s) % AES.block_size)

    def encrypt(self, iv, plaintext):
        #iv = Random.new().read(AES.block_size)
        cipher = AES.new(self.key, AES.MODE_CFB, iv)
        return iv + cipher.encrypt(plaintext)

    def decrypt(self, iv, ciphertext):
        #iv = ciphertext[:AES.block_size]
        cipher = AES.new(self.key, AES.MODE_CFB, iv)
        plaintext = cipher.decrypt(ciphertext[AES.block_size:])
        return plaintext.rstrip(b'\0')

def main(args):
    enc = AESEncryptor(args[0])
    iv = Random.new().read(AES.block_size)
    encrypted = enc.encrypt(iv, ''.join(args[1:]))
    print(encrypted)
    print(enc.decrypt(iv, encrypted))

if __name__ == '__main__':
    main(sys.argv[1:])
