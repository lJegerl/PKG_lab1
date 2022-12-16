#include "convert.h"
#include <cmath>
#include <QtGlobal>
#include <QtMath>

convert::convert()
{
}

void convert::XYZtoRGB(int x, int y, int z) {
    qreal X = x / 100, Y = y / 100, Z = z / 100;

        qreal Rn = 3.2406 * X - 1.5372 * Y - 0.4986 * Z;
        qreal Gn = -0.9689 * X + 1.8758 * Y + 0.0415 * Z;
        qreal Bn = 0.0557 * X - 0.2040 * Y + 1.0570 * Z;
        qreal R = Rn, G = Gn, B = Bn;
        setRed(R);
        setGreen(G);
        setBlue(B);

}

void convert::RGBtoXYZ(int R, int G, int B) {
    float var_R = R / 255;
    float var_G = G / 255;
    float var_B = B / 255;

    if (var_R >= 0.04045) {
        var_R = pow(((var_R + 0.055 ) / 1.055), 2.4);
    }
    else {
        var_R = var_R / 12.92;
    }
    if (var_G >= 0.04045) {
        var_G = pow(((var_G + 0.055) / 1.055), 2.4);
    }
    else {
        var_G = var_G / 12.92;
    }
    if (var_B >= 0.04045) {
        var_B = pow(((var_B + 0.055) / 1.055), 2.4);
    }
    else {
        var_B = var_B / 12.92;
    }

    var_R *= 100;
    var_G *= 100;
    var_B *= 100;

    int X = (var_R * 0.4124) + (var_G * 0.3576) + (var_B * 0.1805);
    int Y = (var_R * 0.2126) + (var_G * 0.7152) + (var_B * 0.0722);
    int Z = (var_R * 0.0193) + (var_G * 0.1192) + (var_B * 0.9505);
    setX(X);
    setY(Y);
    setZ(Z);
}

void convert::XYZtoLAB(int x, int y, int z) {
    float ref_X =  95.047;
    float ref_Y = 100.000;
    float ref_Z = 108.883;

    float var_X = x / ref_X;
    float var_Y = y / ref_Y;
    float var_Z = z / ref_Z;

    if (var_X >= 0.008856) {
        var_X = pow(var_X, 1.0/3);
    }
    else {
        var_X = (var_X * 7.787) + (16 / 116);
    }
    if (var_Y >= 0.008856) {
        var_Y = pow(var_Y, 1.0/3);
    }
    else {
        var_Y = (var_Y * 7.787) + (16 / 116);
    }
    if (var_Z >= 0.008856) {
        var_Z = pow(var_Z, 1.0/3);
    }
    else {
        var_Z = (var_Z * 7.787) + (16 / 116);
    }
    float number_1 = ((116 * var_Y) - 16);
    float number_2 = (500 * (var_X - var_Y));
    float number_3 = (200 * (var_Y - var_Z));
    setCIA_L(number_1);
    setCIA_A(number_2);
    setCIA_B(number_3);
}

void convert::LABtoRGB(int l, int a, int b)
{
    qreal L = l, A = a, B = b;
        qreal Xw = 95.047, Yw = 100, Zw = 108.883;
        qreal X, Y, Z;
        X = (A / 500.0 + (L + 16.0) / 116.0) * Xw;
        Y = ((L + 16) / 116.0) * Yw;
        Z = ((L + 16) / 116.0 - B / 200.0) * Zw;
        XYZtoRGB(X, Y, Z);
}


void convert::setRed(int red) {
    this->red = red;
}

void convert::setGreen(int green) {
    this->green = green;
}

void convert::setBlue(int blue) {
    this->blue = blue;
}

void convert::setX(int x) {
    this->x = x;
}

void convert::setY(int y) {
    this->y = y;
}

void convert::setZ(int z) {
    this->z = z;
}

void convert::setCIA_L(int cia_l) {
    CIA_L = cia_l;
}

void convert::setCIA_A(int cia_a) {
    CIA_A = cia_a;
}

void convert::setCIA_B(int cia_b) {
    this->CIA_B = cia_b;
}

int convert::getX() {
    return x;
}

int convert::getY() {
    return y;
}

int convert::getZ() {
    return z;
}

int convert::getRed() {
    return red;
}

int convert::getGreen() {
    return green;
}

int convert::getBlue() {
    return blue;
}

float convert::getCIA_L() {
    return CIA_L;
}

float convert::getCIA_A() {
    return CIA_A;
}

float convert::getCIA_B() {
    return CIA_B;
}
