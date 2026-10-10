#include <iostream>
#include <string>
#include <algorithm>
#include"Image_class.h"
using namespace std;

// Filter 3: Invert Colors Filter
void invertImage(Image& img) {
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                img(i, j, k) = 255 - img(i, j, k);
            }
        }
    }
}

// Filter 7 (Part A): Lighten Image Filter
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

// Filter 7 (Part B): Darken Image Filter
void darkenImage(Image& img) {
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                img(i, j, k) = img(i, j, k) * 0.5;
            }
        }
    }
}

// Filter 11: Crop Image Filter
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

// Filter 15: Purple Tint Filter
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

    cout << "------- Welcome to Baby PhotoShop -------  " << endl;
    cout << "Please enter the image file name to load: ";
    cin >> filename;
   Image currentImage(filename);
   if (currentImage.width <= 0 || currentImage.height <= 0) {
        cout << "Error: File not found or invalid format!" << endl;
        return 1;
    }
    cout << "Image loaded successfully!" << endl;
    
    
    int choice = 0;
    while (choice != 20) {
        
        cout << "---------------- Main Menu ----------------" << endl;
        cout << "3. Invert Colors" << endl;
        cout << "7. Darken / Lighten " << endl;
        cout << "11. Crop Image" << endl;
        cout << "15. Purple Tint" << endl;
        cout << "19. Save the current image" << endl;
        cout << "20. Exit" << endl;
        cout << "Choose an option:   ";
        cin >> choice;

        switch (choice) {
            case 3: {

                invertImage(currentImage);
                cout << "Invert filter applied successfully!" << endl;
                break;
            }

            case 7 : {
               
                int subChoice;
                cout << "Choose adjustment type:" << endl;
                cout << "1. Lighten image" << endl;
                cout << "2. Darken image " << endl;
                cout << "Enter choice (1 or 2): ";
                cin >> subChoice;

                if (subChoice == 1) {
                    lightenImage(currentImage);
                    cout << "Image lightened successfully!" << endl;
                } else if (subChoice == 2) {
                    darkenImage(currentImage);
                    cout << "Image darkened successfully!" << endl;
                } else {
                    cout << "Invalid choice!" << endl;
                }
                break;
            }

            case 11: {
                int x, y, width, height;
                cout << "Current image size: " << currentImage.width << " x " << currentImage.height << endl;

                while (true) {
                    cout << "Enter start position X: ";
                    cin >> x;
                    cout << "Enter start position Y: ";
                    cin >> y;
                    cout << "Enter crop Width: ";
                    cin >> width;
                    cout << "Enter crop Height: ";
                    cin >> height;

                    if (x < 0 || y < 0 || width <= 0 || height <= 0 || 
                        x + width > currentImage.width || y + height > currentImage.height) {
                        cout << "Invalid dimensions! The crop area must be within the image bounds. Try again." << endl;
                    } else {
                        break; 
                    }
                
                }  
                cropimage(currentImage, x, y, width, height);
                cout << "Image cropped successfully!" << endl;
                break;
            }

            case 15: {

                purplefilter(currentImage);
                cout << "Purple filter applied successfully!" << endl;
                break;
            }

            case 19: {
            string outputName;
            cout << "Enter output image name: ";
            cin >> outputName;
            currentImage.saveImage(outputName);
            cout << "Image saved successfully as: " << outputName << endl;
            
            int nextStep;
            while (true) {
                cout << "\nDo you want to edit another image?" << endl;
                cout << "1. Yes (Load new image)" << endl;
                cout << "2. No (Exit)" << endl;
                cin >> nextStep;

                if (nextStep == 1) {
                    cout << "\n--- Load New Image ---" << endl;
                    while (true) {
                        cout << "Please enter the new image file name to load: ";
                        cin >> filename;

                        Image newImage(filename);
                        if (newImage.width <= 0 || newImage.height <= 0) {
                            cout << "Error: File not found or invalid format! Try again." << endl;
                            continue;
                        }

                        currentImage = newImage;
                        cout << "New image loaded successfully!" << endl;
                        break;
                    }
                    break;
                } 
                else if (nextStep == 2) {
                    choice = 20; 
                    cout << "Exiting program. Goodbye!" << endl;
                    break; 
                } 
                else {
                    cout << "Invalid choice! Please enter 1 or 2." << endl;
                }
            }
            break;
        }
            case 20:
                cout << "Exiting program. Goodbye!" << endl;
                break;

            default:{
                cout << "Invalid option! Please enter a number between 1 and 20." << endl;
                break;
            }
        }
    }

    return 0;
}