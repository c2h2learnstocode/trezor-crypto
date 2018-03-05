#include <stdio.h>
#include <bip39.h>
#include <sha2.h>
#include <sodium.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>

int main()
{
    const int64_t diff = 100000000000000LL;
    uint8_t * m;
    uint8_t * m2 = malloc(sizeof(uint8_t)*32);
    unsigned char  * sk=malloc(sizeof(unsigned char)*32);
    unsigned char  * pk=malloc(sizeof(unsigned char)*32);
    uint8_t *sha256_1=malloc(sizeof(uint8_t)*32);
    int i,j;
    int64_t lisk_addr;
    char char_lisk_addr[30];
    char *msg=malloc(sizeof(char)*32);

    while(1){
        m = mnemonic_generate(128);
        //m = "opinion rabbit unveil document clay faith analyst behind habit cricket light turkey";
        sha256_Raw(m, strlen(m), sha256_1);
        crypto_sign_seed_keypair(pk, sk, sha256_1);
        sha256_Data(pk, strlen(pk), m2);
        
        lisk_addr =0;
        for(j=0; j< 8; j++){
            msg[j*2] = m2[14-j*2];
            msg[j*2+1] = m2[15-j*2];
        }
        lisk_addr = strtoull(msg, NULL, 16);
        

        sprintf(char_lisk_addr, "%lld", lisk_addr); 
        if(strlen(char_lisk_addr)< 15){
            printf("%d  %lluL  %s\n", strlen(char_lisk_addr), lisk_addr, m);
        }
    }
    return 0;
}
