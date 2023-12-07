// RGBApixmap.h

#include <string>
#include <iostream>
#include <fstream>
#include <GL/glut.h>

using namespace std;

struct RGB {
    unsigned char r, g, b;
};

class RGBpixmap {
private:
    int nRows, nCols;
    RGB* pixel;

public:
    RGBpixmap() {
        nRows = nCols = 0;
        pixel = 0;
    }

    RGBpixmap(int r, int c) {
        nRows = r;
        nCols = c;
        pixel = new RGB[r * c];
    }

    void setPixel(int x, int y, RGB color) {
        if (x >= 0 && x < nCols && y >= 0 && y < nRows)
            pixel[nCols * y + x] = color;
    }

    RGB getPixel(int x, int y) {
        return pixel[nCols * y + x];
    }

    void Draw() {
        glDrawPixels(nCols, nRows, GL_RGB, GL_UNSIGNED_BYTE, pixel);
    }

    void read(int x, int y, int wid, int ht) {
        nRows = ht;
        nCols = wid;
        pixel = new RGB[nRows * nCols];
        if (!pixel)
            exit(-1);
        glReadPixels(x, y, nCols, nRows, GL_RGB, GL_UNSIGNED_BYTE, pixel);
    }

    void copy(int x, int y, int wid, int ht) {
        glCopyPixels(x, y, wid, ht, GL_COLOR);
    }

    int readBMPFile(char* fname);

    int writeBmpFile(char* fname);

    // Add the setChromakey method here
    void setChromakey(unsigned char r, unsigned char g, unsigned char b) {
        for (int i = 0; i < nCols * nRows; ++i) {
            if (pixel[i].r == r && pixel[i].g == g && pixel[i].b == b) {
                // Set the alpha channel to 0 for the chroma key color
                pixel[i].r = 0;
            }
        }
    }
};

