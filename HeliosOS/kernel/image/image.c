#include "image.h"
#include "../gfx/framebuffer.h"
#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t type;
    uint32_t size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset;
} BMPHeader;

typedef struct {
    uint32_t size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bits;
    uint32_t compression;
    uint32_t image_size;
    int32_t x_ppm;
    int32_t y_ppm;
    uint32_t colors;
    uint32_t important;
} DIBHeader;
#pragma pack(pop)

image_t* load_bmp(const void* data)
{
    const uint8_t* bytes = (const uint8_t*)data;

    BMPHeader* bmp = (BMPHeader*)bytes;
    DIBHeader* dib = (DIBHeader*)(bytes + sizeof(BMPHeader));

    if (bmp->type != 0x4D42) return 0; // "BM"

    if (dib->bits != 24) return 0; // только 24-bit BMP

    image_t* img = (image_t*)malloc(sizeof(image_t));
    img->width = dib->width;
    img->height = dib->height;
    img->pixels = (uint32_t*)malloc(img->width * img->height * 4);

    uint8_t* pixel_data = (uint8_t*)(bytes + bmp->offset);

    int row_padded = (img->width * 3 + 3) & (~3);

    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {

            uint8_t* pixel = pixel_data + (img->height - y - 1) * row_padded + x * 3;

            uint8_t b = pixel[0];
            uint8_t g = pixel[1];
            uint8_t r = pixel[2];

            img->pixels[y * img->width + x] =
                (0xFF << 24) | (r << 16) | (g << 8) | b;
        }
    }

    return img;
}

void draw_image(image_t* img, int x, int y)
{
    for (uint32_t j = 0; j < img->height; j++) {
        for (uint32_t i = 0; i < img->width; i++) {

            uint32_t color = img->pixels[j * img->width + i];

            uint32_t dx = x + i;
            uint32_t dy = y + j;

            if (dx >= fb_width || dy >= fb_height) continue;

            fb_put_pixel(dx, dy, color);
        }
    }
}

void free_image(image_t* img)
{
    if (!img) return;
    free(img->pixels);
    free(img);
}
