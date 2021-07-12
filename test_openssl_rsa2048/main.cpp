#include <iostream>
#include <openssl/rsa.h>
#include <openssl/pem.h>

int main(int argc, char **argv)
{
  int ret = 0;

  RSA *rsa = RSA_new();
  BIGNUM *bne = BN_new();

  BIO *bp_public = nullptr;
  BIO *bp_private = nullptr;

  try
  {
    ret = BN_set_word(bne, RSA_F4);
    if (ret != 1)
    {
      throw std::runtime_error("BN_set_word");
    }

    ret = RSA_generate_key_ex(rsa, 2048, bne, nullptr);
    if (ret != 1)
    {
      throw std::runtime_error("RSA_generate_key_ex");
    }

    bp_public = BIO_new_file("public.pem", "w+");
    ret = PEM_write_bio_RSAPublicKey(bp_public, rsa);
    if (ret != 1)
    {
      throw std::runtime_error("PEM_write_bio_RSAPublicKey");
    }

    bp_private = BIO_new_file("private.pem", "w+");
    ret = PEM_write_bio_RSAPrivateKey(bp_private, rsa, nullptr, nullptr, 0, nullptr, nullptr);
    if (ret != 1)
    {
      throw std::runtime_error("PEM_write_bio_RSAPrivateKey");
    }
  }
  catch (const std::runtime_error &e)
  {
    std::cout << e.what() << std::endl;
  }

  BIO_free_all(bp_public);
  BIO_free_all(bp_private);
  RSA_free(rsa);
  BN_free(bne);

  return EXIT_SUCCESS;
}
