#include <iostream>
#include <string>
#include <algorithm>
#include"Image_class.h"
using namespace std;

void invertImage(Image& img) {
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                img(i, j, k) = 255 - img(i, j, k);
            }
        }
    }
}

void adjustBrightness(Image& img, bool lighten) {
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (lighten) {
                    int newVal = img(i, j, k) + (img(i, j, k) * 0.5);
                    img(i, j, k) = min(255, newVal);
                } else {
                    img(i, j, k) = img(i, j, k) * 0.5;
                }
            }
        }
    }
}
 main() {
    string filename;
    cout << "        Welcome to Baby PhotoShop       " << endl;
    cout << "Please enter the image file name to load: ";
    cin >> filename;
    Image currentImage;
    try {
        currentImage.loadNewImage(filename);
        cout << "Image loaded successfully!" << endl;
    } catch (...) {
        cout << "Error: File not found or invalid format!" << endl;
        return 1;
    }

    int choice = 0;
    while (choice != 4) {
        cout << "--------------- Main Menu ----------------" << endl;
        cout << "1. Apply Filter 3: Invert Colors" << endl;
        cout << "2. Apply Filter 7: Darken / Lighten (50%)" << endl;
        cout << "3. Save the current image" << endl;
        cout << "4. Exit" << endl;
        cout << "Choose an option (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                invertImage(currentImage);
                cout << "Invert filter applied successfully!" << endl;
                break;

            case 2: {
                int subChoice;
                cout << "Choose adjustment type:" << endl;
                cout << "1. Lighten image by 50%" << endl;
                cout << "2. Darken image by 50%" << endl;
                cout << "Enter choice (1 or 2): ";
                cin >> subChoice;

                if (subChoice == 1) {
                    adjustBrightness(currentImage, true);
                    cout << "Image lightened by 50% successfully!" << endl;
                } else if (subChoice == 2) {
                    adjustBrightness(currentImage, false);
                    cout << "Image darkened by 50% successfully!" << endl;
                } else {
                    cout << "Invalid choice!" << endl;
                }
                break;
            }

            case 3: {
                string outputName;
                cout << "Enter output image name: ";
                cin >> outputName;
                try {
                    currentImage.saveImage(outputName);
                    cout << "Image saved successfully as: " << outputName << endl;
                } catch (...) {
                    cout << "Failed to save the image!" << endl;
                }
                break;
            }

            case 4:
                cout << "Exiting program. Goodbye!" << endl;
                break;
                default:
                cout << "Invalid option! Please enter a number between 1 and 4." << endl;
                break;
        }
    }

    return 0;
}