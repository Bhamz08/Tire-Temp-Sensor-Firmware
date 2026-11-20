#ifndef MLX90614_H
#define MLX90614_H

#include <stdint.h>

/* Temperatures in milli-degrees C (25.5 degC = 25500). Integers avoid
 * floating point, which is slow or missing on small MCUs. */
struct mlx90614_reading {
	int32_t obj_milli_c; /* object = the tire surface */
	int32_t amb_milli_c; /* ambient = the sensor package itself */
};

/* Check the I2C bus is ready. Returns 0 or -ENODEV. */
int mlx90614_init(void);

/*
 * Read object temp (reg 0x07) then ambient temp (reg 0x06).
 * On success fills *out and returns 0. On failure leaves *out untouched and
 * returns the first error:
 *   -EIO     I2C transfer failed (no ACK, wiring, etc.)
 *   -EBADMSG PEC (checksum) mismatch
 *   -ENODATA sensor set its error flag
 */
int mlx90614_read(struct mlx90614_reading *out);

#endif
