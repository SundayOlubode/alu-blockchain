#include "hblk_crypto.h"

/**
 * sha256 - computes the hash of a sequence of bytes
 * @s: sequence of bytes to hash
 * @len: number of bytes to hash in s
 * @digest: array to store resulting hash
 *
 * Return: pointer to digest, or NULL on failure
 */
uint8_t *sha256(int8_t const *s, size_t len, uint8_t digest[SHA256_DIGEST_LENGTH])
{
        // init algorithm context
        // update context with hash
        // finalize hash computation

        EVP_MD_CTX *context = NULL;
        EVP_MD *algorithm = NULL;

        if (digest == NULL)
        {
                return (NULL);
        }

        context = EVP_MD_CTX_new();
        if (!context)
        {
                return (NULL);
        }

        algorithm = EVP_MD_fetch(NULL, "SHA256", NULL);
        // algorithm = EVP_sha256();

        if (!EVP_DigestInit_ex(context, algorithm, NULL))
        {
                printf("Error initializing hash function\n");
        }

        if (!EVP_DigestUpdate(context, s, len))
        {
                printf("Error updating hash\n");
        }

        if (!EVP_DigestFinal_ex(context, digest, &len))
        {
                printf("Error finalizing hash\n");
        }

        return (digest);

        printf("Digest: %s\n", &digest);
}

// int main(void)
// {
//         uint8_t digest[SHA256_DIGEST_LENGTH];
//         uint8_t *hash;
//         size_t len = 9;

//         hash = sha256("Holberton", len, digest);
//         if (!hash)
//         {
//                 printf("sha256() failed\n");
//         }

//         printf("SHA256 Hash: ");

//         return (0);
// }