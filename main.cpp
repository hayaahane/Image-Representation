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

void lightenImage(Image& img) {
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            for (int k = 0; k < 3; ++k) {
         int newVal = img(i, j, k) + (img(i, j, k) * 0.5); 
              img(i, j, k) = min(255, newVal);

            }

        }
    }
}

void darkenImage(Image& img) {
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                img(i, j, k) = img(i, j, k) * 0.5;
            }
        }
    }
}
void cropimage(Image& image, int x, int y, int width, int height) {
	Image croppedImage(width, height);
	for (int i = 0; i < width; ++i) {
		for (int j = 0; j < height; ++j) {
			for (int k = 0; k < 3; ++k) {
				croppedImage(i, j, k) = image(x + i, y + j, k);
			}
		}
	}
	image = croppedImage;
}
void purplefilter(Image& image) {
	for (int i = 0; i < image.width; ++i) {
		for (int j = 0; j < image.height; ++j) {
			int r = image(i, j, 0) + 40;
			if (r > 255) r = 255;
			image(i, j, 0) = r;
			image(i, j, 1) = image(i, j, 1) * 0.7;
		}
	}
}
int main() {
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
    Image originalImage = currentImage;
    int choice = 0;
    while (choice != 6) {
        
        cout << "\n--------------- Main Menu ----------------" << endl;
        cout << "1. Apply Filter 3: Invert Colors" << endl;
        cout << "2. Apply Filter 7: Darken / Lighten (50%)" << endl;
        cout << "3. Apply Filter 11: Crop Image" << endl;
        cout << "4. Apply Filter 15: Purple Tint" << endl;
        cout << "5. Save the current image" << endl;
        cout << "6. Exit" << endl;
        cout << "Choose an option (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1:{
            currentImage = originalImage;
                invertImage(currentImage);
                cout << "Invert filter applied successfully!" << endl;
                break;
            }

            case 2: {
               currentImage = originalImage; 
                int subChoice;
                cout << "Choose adjustment type:" << endl;
                cout << "1. Lighten image by 50%" << endl;
                cout << "2. Darken image by 50%" << endl;
                cout << "Enter choice (1 or 2): ";
                cin >> subChoice;

                if (subChoice == 1) {
                    lightenImage(currentImage);
                    cout << "Image lightened by 50% successfully!" << endl;
                } else if (subChoice == 2) {
                    darkenImage(currentImage);
                    cout << "Image darkened by 50% successfully!" << endl;
                } else {
                    cout << "Invalid choice!" << endl;
                }
                break;
            }

            case 3: {
                currentImage = originalImage;
                int x, y, width, height;
                cout << "Current image size: " << currentImage.width << " x " << currentImage.height << endl;
                cout << "Enter x, y, width, height: ";
                cin >> x >> y >> width >> height;
                cropimage(currentImage, x, y, width, height);
                break;
            }

            case 4:{
             currentImage = originalImage;
                purplefilter(currentImage);
                cout << "Purple filter applied successfully!" << endl;
                break;
            }

            case 5: {
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

            case 6:
                cout << "Exiting program. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid option! Please enter a number between 1 and 6." << endl;
                break;
        }
    }

    return 0;
}