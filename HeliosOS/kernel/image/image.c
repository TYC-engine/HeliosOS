#include "image.h"
#include "png/png.h"

Image* load_image(const char* path) {
    // очень примитивно: проверка расширения
    const char* ext = path + strlen(path) - 4;

    if (strcmp(ext, ".png") == 0) {
        return png_load(path);
    }

    return 0;
}
