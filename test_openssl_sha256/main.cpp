#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <openssl/sha.h>
#include <openssl/hmac.h>
#include <openssl/evp.h>

void sha256(char *string, char outputBuffer[65])
{
  unsigned char hash[SHA256_DIGEST_LENGTH];
  SHA256_CTX sha256;
  SHA256_Init(&sha256);
  SHA256_Update(&sha256, string, strlen(string));
  SHA256_Final(hash, &sha256);
  int i = 0;
  for (i = 0; i < SHA256_DIGEST_LENGTH; i++)
  {
    sprintf(outputBuffer + (i * 2), "%02x", hash[i]);
  }
  outputBuffer[64] = 0;
}

int main(void)
{
  char buffer[65];
  sha256("string", buffer);
  printf("%s\n", buffer);

  return 0;
}