#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <stdlib.h>
#include <stdio.h>


char picturegetCharForBrightness(int brightness) {
    char chars[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};
    int numChars = 10;
    int brightnessStep = 255 / numChars;

    int index = brightness / brightnessStep;
    if (index >= numChars) {
        index = numChars - 1;
    }

    return chars[index];
}

void pictureFromPngToSymbol(const int i,char picture[]) {
    int width, height, channels;


    unsigned char* image = stbi_load("C:\\Users\\dimak\\CLionProjects\\lab1\\pictures\\run.png", &width, &height, &channels, 0);

    //char symbols[180];
    if (image != NULL) {
        // Масштабируем изображение до 45x100
        unsigned char scaledImage[45 * 100];
        for (int y = 0; y < 45; y++)
        {
            for (int x = 0; x < 100; x++)
            {
                int origX = x * width / 100;
                int origY = y * height / 45;
                int index = (origY * width + origX) * channels;
                int brightness = (int)(0.2126f * image[index] + 0.7152f * image[index + 1] + 0.0722f * image[index + 2]);
                scaledImage[y * 100 + x] = brightness;
            }
        }

        // Преобразуем масштабированное изображение в символьное представление
        for (int i = 0; i < 4500; i++)
        {
            picture[i] = picturegetCharForBrightness(scaledImage[i]);
        }

        stbi_image_free(image);

    }
    else
    {
        printf("Error\n");
    }

}