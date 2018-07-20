#include <iostream>
#include <iomanip>
#include <openssl/evp.h> 
#include <sstream>
#include <string>
#include "sha256.h"

string sha256(string msg) {

    const char* message = msg.data();
   
	EVP_MD_CTX ctx1, ctx2;
    unsigned char digest_round1[EVP_MAX_MD_SIZE];
    unsigned char digest_round2[EVP_MAX_MD_SIZE];
    unsigned int outLen_1;
    unsigned int outLen_2;

    EVP_DigestInit(&ctx1, EVP_sha256());
    EVP_DigestUpdate(&ctx1, message, msg.length());
    EVP_DigestFinal(&ctx1, digest_round1, &outLen_1);

    EVP_DigestInit(&ctx2, EVP_sha256());
    EVP_DigestUpdate(&ctx2, digest_round1, outLen_1);
    EVP_DigestFinal(&ctx2, digest_round2, &outLen_2);

    stringstream ss;
    for (unsigned int i = 0; i < outLen_2; i++){
        ss << setfill('0') << setw(2) << hex << (int)digest_round2[i];
        //cout << setfill('0') << setw(2) << hex << (int)digest[i];
        // cout << (int)digest_round2[i];
    }

    return ss.str();

}
