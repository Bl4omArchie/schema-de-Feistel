ROUNDS = 13


def xor(text, key):
    result = ""
    for i in range(len(text)):
        result += chr(ord(text[i]) ^ ord(key[i % len(key)]))
    return result

def feistel_schemes(text, key):
    L = text[:len(text)//2]
    R = text[len(text)//2:]

    for _ in range(ROUNDS):
        L = xor(L, xor(R, key))
        tmp = L
        L=R
        R=tmp

    return L+R


if __name__ == "__main__":
    message = "1001001011010101010101"
    key = "super_cle_secrete"

    print (feistel_schemes(message, key))