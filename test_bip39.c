#include <stdio.h>
#include <bip39.h>

int main()
{
    const char *m;
    int i;
    for(i=0;i<1e6;i++)
    {
        m = mnemonic_generate(128);
        printf("%s\n", m);
    }
    return 0;
}
