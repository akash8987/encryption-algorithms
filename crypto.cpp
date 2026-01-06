#include <string>

class CaesarCipher {
private:
    int shift;

    char encryptChar(char c) const {
        if (c >= 'a' && c <= 'z')
            return 'a' + (c - 'a' + shift) % 26;
        if (c >= 'A' && c <= 'Z')
            return 'A' + (c - 'A' + shift) % 26;
        return c;
    }

public:
    explicit CaesarCipher(int s) : shift(s % 26) {}

    std::string encrypt(const std::string& text) const {
        std::string result;
        for (char c : text) {
            result += encryptChar(c);
        }
        return result;
    }
};

int main() {
    CaesarCipher cipher(3);
    cipher.encrypt("SecureMessage");
    return 0;
}
