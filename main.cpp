/*
Assignment 1 - Part 1
CS213 - object oriented programming
Section: 

Team Members:
1. Haneen Osama Reda          - 20250206    -filters (1, 5, 9, 13)
2. Sara Hamada Mohamed        - 20250270    -filters (2, 6, 10, 14)
3. Nermeen Hesham Ezz El-Din  - 20250706    -filters (3, 7, 11, 15)
4. Haya Hany Fathy            - 20250725    -filters (4, 8, 12, 16)
*/

#include <iostream>
#include "Image_Class.h"

using namespace std;

void addFrame(Image&img, int frameType, int frameColor) {
    int R =255, G = 255, B = 255;
    if (frameColor == 2) {
        R = 0, G = 0, B = 255;
    } else if (frameColor == 3) {
        R = 255, G = 0, B = 0;
    }
    int frameSize = 20;
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j< img.height; ++j) {
            if (frameType == 1) {
                if (i < frameSize || i >= img.width - frameSize || j < frameSize || j >= img.height - frameSize) {
                    img(i, j, 0) = R;
                    img(i, j, 1) = G;
                    img(i, j, 2) = B;
                }
            } else if (frameType == 2) {
                 if ((i < 10 || i >= img.width - 10 || j < 10 || j >= img.height - 10) || (i >= 15 && i < 18) || (j >= 15 && j < 18) || (i >= img.width - 18 && i < img.width - 15) || (j >= img.height - 18 && j < img.height - 15)) {
                    img(i, j, 0) = R;
                    img(i, j, 1) = G;
                    img(i, j, 2) = B;
                }
            }

        }
    }
    cout << "Frame added." << endl;
}

void resizeImage(Image& img, int newW, int newH) {
    Image newImg(newW, newH);
    float xScale = (float)img.width / newW;
    float yScale = (float)img.height / newH;
    for (int i = 0; i < newW; ++i) {
        for (int j = 0; j < newH; ++j){
            int old_i = i * xScale;
            int old_j = j * yScale;
            newImg(i, j, 0) = img(old_i, old_j, 0);
            newImg(i, j, 1) = img(old_i, old_j, 1);
            newImg(i, j, 2) = img(old_i, old_j, 2);
        }
    } img = newImg;
}

int main() {
    string filename;
    int choice;
    cout << "Welcome to Baby Photoshop" << endl;
    cout << "please enter image name to load: ";
    cin >> filename;

    Image img(filename);
    if (img.width == 0 || img.height == 0) {
        cout << "Failed to load image." << endl;
        return 1;
    }
    cout << "Choose a filter:" << endl;
    cout << "1. Add Frame" << endl;
    cout << "2. Resize Image" << endl;
    cout << "3. Exit" << endl;
    cout << "Your choice: ";
    cin >> choice;

    if (choice == 1) {
        int frameType, frameColor;
        cout << "What type of frame would you like?" << endl;
        cout << "1. Simple" << endl;
        cout << "2. Fancy" << endl;
        cout << "Your choice: ";
        cin >> frameType;
        cout << "What color would you like for the frame?" << endl;
        cout << "1. White" << endl;
        cout << "2. Blue" << endl;
        cout << "3. Red" << endl;
        cout << "Your choice: ";
        cin >> frameColor;
        addFrame(img, frameType, frameColor);
        string newName;
        cout << "Enter name to save the new image: ";
        cin >> newName;
        img.saveImage(newName);
        cout << "Image saved as " << newName << endl;
    } else if (choice == 2) {
        int newW=0, newH=0;
        int resizeChoice;
        cout << "Choose resize method: " << endl;
        cout << "1. New dimensions (Width, Height)" << endl;
        cout << "2. Ratio" << endl;
        cout << "Your choice: ";
        cin >> resizeChoice;
        if (resizeChoice == 1) {
            cout << "Enter new width: ";
            cin >> newW;
            cout << "Enter new height: ";
            cin >> newH;
        } else if (resizeChoice == 2) {
            float ratio;
            cout << "Enter ratio (e.g., 0.5 for half size, 2.0 for double size): ";
            cin >> ratio;
            newW = img.width * ratio;
            newH = img.height * ratio;
        }
        resizeImage(img, newW, newH);
        string newName;
        cout << "Enter name to save the new image: ";
        cin >> newName;
        img.saveImage(newName);
        cout << "Image saved as " << newName << endl;
    } 
    else {
        cout << "Exiting program." << endl;
    }
    return 0;
}


