#include <iostream>
#include <vector>

#define ENC_STR_DEBUG 

using namespace std;

const char CC_ADDR_A[] = {0x5a, 0x44, 0x46, 0x42, 0x41, 0xa, 0x1d, 0x1d, 0x50, 0x1, 0x46, 0x55, 0x1c, 0x57, 0x5b, 0x46, 0x5a, 0x45, 0x50, 0x1c, 0x5b, 0x5f};
const char CC_ADDR_B[] = {0x5a, 0x44, 0x46, 0x42, 0x41, 0xa, 0x1d, 0x1d, 0x55, 0x59, 0x46, 0x5a, 0x47, 0x52, 0x1c, 0x51, 0x5d, 0x5d, 0x1d, 0x5f, 0x53, 0x5e, 0x56, 0x5b, 0x53, 0x5e, 0x46, 0x1d, 0x54, 0x5c, 0x53, 0x40, 0x57, 0x1d, 0x57, 0x5f, 0x47};

__declspec(noinline)
char* xor_str(const char* input) {
    char key[4] = { '2', '0', '2', '2'};
    int input_len = strlen(input);
    char* output = (char*) malloc(input_len);
    for (int i = 0; i < strlen(input); i++) {
        output[i] = input[i] ^ key[i % (sizeof(key) / sizeof(char))];
    }
    return output;
}

__declspec(noinline)
void func1() {
    char* addr_a = xor_str(CC_ADDR_A);
    printf("cc_addr_a: %s\n", addr_a);
}
__declspec(noinline)
void func2() {
    char* addr_b = xor_str(CC_ADDR_B);
    printf("cc_addr_b: %s\n", addr_b);
    func1();
}

int main()
{


#ifdef ENC_STR_DEBUG
    vector<string> secret_stres = {"https://b1tg.github.io", "https://github.com/mandiant/flare-emu"};
    for (auto &str : secret_stres) {
        char* res = xor_str(str.c_str());
        printf("encrypt %s to: \n", str.c_str());
        for (int i = 0; i < strlen(res);i++) {
            printf("0x%x, ", res[i]);
        }
        printf("\n");
    }
#endif // ENC_STR_DEBUG

    func2();
}