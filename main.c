#include <stdio.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#define NI_GRAYSCALE_IMPLEMENTATION
#include "ni_image_grayscale.h"

#define NI_DITHER_IMPLEMENTATION
#include "ni_image_dither.h"

int
main(const int argc, const char *argv[])
{
    const char* VERSION = "1.0.0";

	if(argc != 2) {
        fprintf(stdout, "NIBWD %s\n\n", VERSION);
		fprintf(stdout, "USAGE:\t%s image_file\n", argv[0]);
		return 1;
	}

	int w, h, n_channels;
	stbi_uc *img_data = stbi_load(argv[1], &w, &h, &n_channels, 3);
	if(img_data == NULL) {
		return 2;
	}

	// Convert to grayscale
	stbi_uc *img_grayscale_240m = ni_image_grayscale_convert(img_data, w, h, n_channels, NI_SMPTE_240M);

	// Dither the image
	stbi_uc *img_dither_240m = ni_image_dither_floydsteinberg_gray2mono(img_grayscale_240m, w, h);

    // Saves the image as BMP (lossless, useful for further processing)
	stbi_write_bmp("output.bmp", w, h, 1, (void *)img_dither_240m);

	stbi_image_free((void *)img_data);
	stbi_image_free((void *)img_grayscale_240m);
	stbi_image_free((void *)img_dither_240m);

	return 0;
}