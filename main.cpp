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
    int FrameSize = 20;
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j< img.height; ++j) {
            if (frameType == 1) {
                if (i < FrameSize || i >= img.width - FrameSize || j < FrameSize || j >= img.height - FrameSize) {
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

int main() {
    string filename;
    int choice;
    cout << "Welcome to Baby Photoshop" << endl;
    cout << "pls enter image name to load: ";
    cin >> filename;

    Image img(filename);
    if (img.width == 0 || img.height == 0) {
        cout << "Failed to load image." << endl;
        return 1;
    }
    cout << "Choose a filter:" << endl;
    cout << "1. Add Frame" << endl;
    cout << "2. Exit" << endl;
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
    } else {
        cout << "Exiting program." << endl;
    }
    return 0;
}


