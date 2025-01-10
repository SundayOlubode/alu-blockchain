#include "hblk_crypto.h"

#define PATH_MAX 256

/**
 * ec_save - Saves EC key pair to disk
 * @key: EC key pair to save
 * @folder: Path to folder where keys will be saved
 *
 * Return: 1 on success, 0 on failure
 */
int ec_save(EC_KEY *key, char const *folder)
{
        char path[PATH_MAX];
        FILE *fp;

        if (!key || !folder)
                return (0);

        if (mkdir(folder, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH) == -1)
        {
                if (errno != EEXIST)
                        return (0);
        }

        snprintf(path, sizeof(path), "%s/key.pem", folder);
        fp = fopen(path, "w");
        if (!fp)
                return (0);
        if (!PEM_write_ECPrivateKey(fp, key, NULL, NULL, 0, NULL, NULL))
        {
                fclose(fp);
                return (0);
        }
        fclose(fp);

        snprintf(path, sizeof(path), "%s/key_pub.pem", folder);
        fp = fopen(path, "w");
        if (!fp)
                return (0);
        if (!PEM_write_EC_PUBKEY(fp, key))
        {
                fclose(fp);
                return (0);
        }
        fclose(fp);

        return (1);
}