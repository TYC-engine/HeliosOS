#pragma once

typedef struct {
    int width;
    int height;
    unsigned char* data; // RGBA8888
} Image;

Image* load_image(const char* path);
void free_image(Image* img);
