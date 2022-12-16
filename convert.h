#ifndef CONVERT_H
#define CONVERT_H


class convert
{
public:
    convert();
    void RGBtoXYZ(int R, int G, int B);
    void XYZtoRGB(int x, int y, int z);
    void XYZtoLAB(int x, int y, int z);
    void LABtoRGB(int l, int a, int b);
    void LABtoXYZ(int l, int a, int b);

    void setCIA_L(int cia_l);
    void setCIA_A(int cia_a);
    void setCIA_B(int cia_b);
    void setX(int x);
    void setY(int y);
    void setZ(int z);
    void setRed(int red);
    void setGreen(int green);
    void setBlue(int blue);
    float getCIA_L();
    float getCIA_A();
    float getCIA_B();
    int getRed();
    int getGreen();
    int getBlue();
    int getX();
    int getY();
    int getZ();
private:
    int red;
    int green;
    int blue;
    int x;
    int y;
    int z;
    float CIA_L;
    float CIA_A;
    float CIA_B;
};

#endif // CONVERT_H
