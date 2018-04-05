#include "keccakhash.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "sha3/sph_keccak.h"

void keccak_hash(const char* input, char* output)
{   
    sph_keccak256_context    ctx_keccak;

    uint8_t hash[32];

    sph_keccak256_init(&ctx_keccak);
    sph_keccak256 (&ctx_keccak, input, strlen(input));
    sph_keccak256_close(&ctx_keccak, hash);

    memcpy(output, hash, 32);
}
