#include "hblk_crypto.h"

EC_KEY *ec_create(void)
{
	return (EC_KEY_new_by_curve_name(NID_secp256k1));
}