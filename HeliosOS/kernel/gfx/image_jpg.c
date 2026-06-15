#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "image.h"

image_t* load_jpg_from_memory(const void* data, size_t size)
{
    int w, h, c;

    unsigned char* imgdata = stbi_load_from_memory(
        (const unsigned char*)data,
        size,
        &w, &h, &c,
        4
    );

    if (!imgdata) return 0;

    image_t* img = malloc(sizeof(image_t));
    img->width = w;
    img->height = h;
    img->pixels = (uint32_t*)imgdata;

    return img;
}
