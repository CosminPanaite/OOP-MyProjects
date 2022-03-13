//
// Created by Cosmin on 29/03/2021.
//
#include <iostream>
#include <cstring>

using namespace std;

#include "Console.h"
#include "Image.h"
#include "ImageProcessing.h"
#include "DrawShapes.h"

Console::Console() {
    run = -1;
}

Console::Console(int run1) {
    this->run = run1;
}

Console::~Console() {
    run = -1;
}

void Console::printMenu() {
    cout << "1. Load PGM file" << endl; ///load_lena.pgm
    cout << "2. Save PGM file" << endl; ///save_Lena.pgm
    cout << "3. Get ROI using Rectangle Class" << endl; /// a region of intrest GetRoiUsingRectangleClass
    cout << "4. Get ROI using 4 paramteres - x,y-coorinates, width, height" << endl; /// getRectangRoi
    cout << "5. Adjust the contrast and the brightness of the image" << endl; /// adjustLena.pgm
    cout << "6. Apply gamma correction to the image" << endl; /// gammaCorrectionLena;
    cout << " 7. Apply image convulition with identity kernel" << endl; ///ConvolutionLena;
    cout << "8. Draw a rectangle on the image using the Rectangle Class" << endl; ///DrawRectangle.pgm
    cout << "9. Draw a rectangle on the image using the Point Class" << endl;   ///DrawRectangle.pgm
    cout << "10. Draw lines on the image using the Point Class" << endl;    ///DrawCircles.pgm
    cout << "11. Draw dots on the image using the Point Class" << endl; ///DrawDots
    cout << "x. EXIT" << endl;
    cout << endl;
}

void Console::runConsole() {
    char option[2];
    ImageProcessing ip(1, 10, 0);
    Image i1;
    Image i2;
    Image i3;
    Image kernel;
    Rectangle rectangle(0, 0, 512, 512);
    DrawShapes comm(1);
    Point tl(0, 0);
    Point br(256, 256);

    while (true) {
        printMenu();
        cout << "Select the option:" << endl;
        cin >> option;
        if (strcmp(option, "1") == 0) {
            bool ok1 = i1.load("C:\\Users\\Cosmin\\CLionProjects\\image_extra\\PGM_FILES\\load_Lena.pgm");
            if (ok1)
                cout << "The image has been successfully loaded." << endl;
            cout << endl;
        } else if (strcmp(option, "2") == 0) {
            bool ok2 = i1.save("C:\\Users\\Cosmin\\CLionProjects\\image_extra\\PGM_FILES\\save_Lena.pgm");
            if (ok2)
                cout << "The image has been successfully saved." << endl;
            cout << endl;
        } else if (strcmp(option, "3") == 0) {
            bool ok4 = i3.load("C:\\Users\\Cosmin\\CLionProjects\\image_extra\\PGM_FILES\\load_Apollo.pgm");
            ok4 = i3.save("C:\\Users\\Cosmin\\CLionProjects\\image_extra\\PGM_FILES\\save_Apollo.pgm");
            bool roi1 = i3.getROI(i3, rectangle);
            if (roi1)
                cout << "The region of interest using Rectangle Class ha been loaed successfully" << endl;
            cout << endl;
        } else if (strcmp(option, "4") == 0) {
            bool roi2 = i1.getROI(i3, 0, 0, 256, 256);
            if (roi2)
                cout << "The region of interest using 4 parameters have been loaed successfully" << endl;
            cout << endl;
        } else if (strcmp(option, "5") == 0) {
            ip.adjustBrightnessConstrast(i1, 1, 40);
            cout << endl;
        } else if (strcmp(option, "6") == 0) {
            ip.gammaCorrection(i1, 0, 100);
            cout << endl;
        } else if (strcmp(option, "7") == 0) {
            bool k1 = kernel.load("C:\\Users\\Cosmin\\CLionProjects\\image_extra\\PGM_FILES\\loadKernel.pgm");
            bool k2 = kernel.save("C:\\Users\\Cosmin\\CLionProjects\\image_extra\\PGM_FILES\\saveKernel.pgm");
            ip.ImageConvolution(i1, kernel);
            cout << endl;
        } else if (strcmp(option, "8") == 0) {
            bool ok3 = i2.load("C:\\Users\\Cosmin\\CLionProjects\\image_extra\\PGM_FILES\\load_Brain.pgm");
            ok3 = i2.save("C:\\Users\\Cosmin\\CLionProjects\\image_extra\\PGM_FILES\\save_Brain.pgm");
            comm.drawRectangle(i2, rectangle, 255);
            cout << endl;
        } else if (strcmp(option, "9") == 0) {
            comm.drawRectangle(i2, tl, br, 128);
            cout << endl;
        } else if (strcmp(option, "10") == 0) {
            Point t1(0, 0);
            Point b1(100, 100);
            comm.drawLine(i2, t1, b1, 255);
            cout << "The lines have been successfully drawn on the image" << endl;
            cout << endl;
        } else if (strcmp(option, "11") == 0) {
            Point t2(0, 0);
            Point b2(120, 120);
            comm.drawDots(i2, t2, b2, 0);
            cout << endl;
        } else if (strcmp(option, "x") == 0) {
            cout << "EXIT" << endl;
            break;
        }
    }
}

