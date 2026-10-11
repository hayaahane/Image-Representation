<<<<<<< HEAD
#include<iostream>
#include"Image_Class.h"
using namespace std;

//Filter 1: Grayscale Conversion
void GrayScale(Image&img) {
    for ( int i=0 ; i < img.width ; i++){
        for (int j=0 ; j < img.height ; j++){
            unsigned int avg=0;

            for (int k=0 ; k < 3 ; k++){
                avg+= img(i,j,k);
            }
            avg /=3 ;
            img.setPixel(i,j,0,avg);
            img.setPixel(i,j,1,avg);
            img.setPixel(i,j,2,avg);
        }
    }
}

//Filter 5: Flip Image
void  HorizontalFlip (Image&img) {
    for(int i=0 ; i < img.width/2 ; i++){
        for(int j=0 ; j < img.height ; j++){
            for(int k=0 ; k < 3 ; k++){
                unsigned char temp= img(i,j,k);
                img(i,j,k) = img(img.width-i-1,j,k);
                img(img.width-i-1,j,k)= temp;


            }
        }

    }

}


void VerticalFlip(Image&img){
    for(int i=0 ; i < img.width ; i++){
        for(int j=0 ; j < img.height/2 ; j++){
            for(int k=0 ; k < 3 ; k++){
                unsigned char temp = img(i,j,k);
                img(i,j,k)= img(i,img.height-j-1,k);
                img(i,img.height-j-1,k)= temp;
=======

/*
Assignment 1 - Part 1
CS213 - object oriented programming
Section: S11

Team Members:
1. Haneen Osama Reda          - 20250206    -filters (1, 5, 9, 13)
2. Sara Hamada Mohamed        - 20250270    -filters (2, 6, 10, 14)
3. Nermeen Hesham Ezz El-Din  - 20250706    -filters (3, 7, 11, 15)
4. Haya Hany Fathy            - 20250725    -filters (4, 8, 12, 16)
*/

#include <iostream>
#include "Image_Class.h"
#include <string>
#include <algorithm>
using namespace std;

// Filter 3: Invert Colors Filter
void invertImage(Image& img) {
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                img(i, j, k) = 255 - img(i, j, k);
>>>>>>> 9e933a506373265dc7991a6d31b49f70d75cc911
            }
        }
    }
}

<<<<<<< HEAD

//Filter 9: Merge Images

Image  Merge(Image&img1 , Image&img2  , int mergeMethod){
    if(img1.width==img2.width && img1.height==img2.height){
        Image mergedImg(img1.width , img1. height);

        for(int i=0 ; i < img1.width ; i++){
            for(int j=0 ; j < img1.height ; j++){
                for(int k=0 ; k < 3 ; k++){

                    mergedImg(i,j,k)=(img1(i,j,k) + img2(i,j,k))/2 ;

                }
            }
        }
        return mergedImg ;
    }
    else if(mergeMethod==1){
        int newWidth = min(img1.width , img2.width);
        int newHeight = min(img1.height, img2.height);

        Image mergedImg(newWidth, newHeight);

        for(int i=0 ; i < newWidth ; i++){
            for(int j=0 ; j < newHeight ; j++){
                for(int k=0 ; k<3 ; k++){
                   
                 mergedImg(i,j,k)=(img1(i,j,k) + img2(i,j,k))/2 ;

                }
            }
        }
        return mergedImg ;
    }
    else if(mergeMethod==2){
        int newWidth = max(img1.width , img2.width);
        int newHeight= max(img1.height , img2.height);

        Image mergedImg(newWidth, newHeight);

        for(int i=0 ; i< newWidth ; i++){
            for(int j= 0 ; j< newHeight ; j++){
                for(int k=0 ; k<3 ; k++){
 
                    int img1_x = i * img1.width / newWidth ;
                    int img1_y = j * img1.height /newHeight ;
                    
                    int img2_x = i * img2.width / newWidth ;
                    int img2_y = j * img2.height /newHeight ;


                    mergedImg(i,j,k)=(img1(img1_x , img1_y , k) + img2(img2_x , img2_y , k)) / 2;
                    
=======
// filter 4: Add Frame 
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
>>>>>>> 9e933a506373265dc7991a6d31b49f70d75cc911
                }
            }

        }
<<<<<<< HEAD
        return mergedImg;
    }
}


//Filter 13:Wano Sunlight

void wanoSunlight(Image&img){
    for(int i=0 ; i<img.width ; i++){
        for(int j=0 ; j<img.height ; j++){
            img(i ,j , 0)=min(255 , img(i,j,0)+60);
            img(i , j , 1)= min(255 , img(i , j , 1)+40);
            img(i , j , 2)= max(0 , img(i , j , 2)-20);
        }
    }
}
    


int main(){
    string filename;

    cout << "------- Welcome to Baby Photoshop -------" << endl;
    cout << "Please enter the image file name to load: ";
    cin >> filename;

    Image currentImage(filename);
    if (currentImage.width <= 0 || currentImage.height <= 0) {
        cout << "Error: File not found or invalid format!" << endl;
        return 1;
    }
    cout << "Image loaded successfully!" << endl;    
    
    int choice = 0; 

    while (choice != 20)
    {
        cout << "---------------- Main Menu ----------------" << endl;
        cout << "1. GrayScale" << endl;
        cout << "5. Flip" << endl;
        cout << "9. Merge" << endl; 
        cout << "13. Wano Sunlight" << endl; 
        cout << "19. Save the current image" << endl; 
        cout << "20. Exit" << endl; 
        cout << "Choose an option: "; 
        cin >> choice;


        switch (choice)
         { 
            case 1:
            {
                GrayScale(currentImage); 
                cout << "GrayScale applied successfully!" << endl;
                break;
            }


            case 5:
            { 
                int flipChoice; 
                cout << "Choose Flip type:" << endl; 
                cout << "1. Horizontal Flip" << endl; 
                cout << "2. Vertical Flip" << endl; 
                cout << "Enter your choice: "; 
                cin >> flipChoice;

                if (flipChoice == 1) 
                { 
                    HorizontalFlip(currentImage); cout << "Horizontal Flip applied successfully!" << endl; 
                } 
                else if (flipChoice == 2) 
                { 
                    VerticalFlip(currentImage); cout << "Vertical Flip applied successfully!" << endl; 
                } 
                else 
                { 
                    cout << "Invalid choice!" << endl; 
                } 
                break; 
            }


            case 9: 
            { 
                string filename2; cout << "Please enter the second image name: "; 
                cin >> filename2; 

                Image currentImage2(filename2); 

                if (currentImage2.width <= 0 || currentImage2.height <= 0) 
                { 
                    cout << "Error: File not found or invalid format!" << endl; 
                    
                    break; 
                } 

                int mergeMethod = 0; 

                if (currentImage.width != currentImage2.width || currentImage.height != currentImage2.height) 
                { 
                    cout << "Choose Merge type:" << endl; 
                    cout << "1. Common Area" << endl; 
                    cout << "2. Resize" << endl; 
                    cout << "Enter your choice: "; 
                    cin >> mergeMethod; 
                    
                    if (mergeMethod != 1 && mergeMethod != 2) 
                    { 
                        cout << "Invalid choice!" << endl; 
                        break; 
                    } 
                }

                currentImage = Merge(currentImage, currentImage2, mergeMethod); 
                
                cout << "Images merged successfully!" << endl; 
                break; 
            }


            case 13: 
            { 
                wanoSunlight(currentImage); 
                cout << "Wano Sunlight applied successfully!" << endl; 
                break; 
            }


            case 19: 
            { 
                string outputName; 

                cout << "Enter output image name: "; 
                cin >> outputName; 
                
                currentImage.saveImage(outputName); 
                
                cout << "Image saved successfully as: " << outputName << endl; 
                
                int nextStep; 
                
                while (true) 
                { 
                    cout << "\nDo you want to edit another image?" << endl; 
                    cout << "1. Yes (Load new image)" << endl; 
                    cout << "2. No (Exit)" << endl; 
                    cout << "Enter your choice: "; 
                    cin >> nextStep; 
                    
                    if (nextStep == 1) 
                    { 
                        cout << "\n--- Load New Image ---" << endl;
                        
                        while (true) 
                        { 
                            cout << "Please enter the new image file name to load: "; 
                            cin >> filename; 
                            
                            Image newImage(filename); 
                            if (newImage.width <= 0 || newImage.height <= 0) 
                            { 
                                cout << "Error: File not found or invalid format! Try again." << endl; 
                                continue; 
                            } 
                            
                            currentImage = newImage; 
                            cout << "New image loaded successfully!" << endl; 
                            break; 
                        } 
                        break; 
                    } 
                    else if (nextStep == 2) 
                    { 
                        choice = 20; cout << "Exiting program. Goodbye!" << endl; 
                        break; 
                    } 
                    else 
                    { 
                        cout << "Invalid choice! Please enter 1 or 2." << endl; 
                    } 
                } 

                break; 
            }
            
            case 20: 
            { 
                cout << "Exiting program. Goodbye!" << endl; 
                break; 
            } 
            default: 
            { 
                cout << "Invalid option! Please enter a valid menu number." << endl; 
                break; 
            } 
        } 
    } 
    return 0; 
}



=======
    }
    cout << "Frame added." << endl;
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


// filter 8 : Resize Image
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

//filter 12 : Blur Image
void blurImage (Image& img, int blurSize){
    Image temp = img;
    for (int i=0; i < img.width; ++i){
        for (int j=0; j < img.height; ++j){
            for (int k=0; k<3; ++k){
                int sum = 0;
                int count =0;
                for (int x = -blurSize; x <= blurSize; ++x){
                    for (int y = -blurSize; y <= blurSize; ++y){
                        int aroundI = i + x;
                        int aroundJ = j + y;
                        if (aroundI >= 0 && aroundI < img.width && aroundJ >= 0 && aroundJ < img.height){
                            sum += temp(aroundI, aroundJ, k);
                            count++;
                        }
                    }
                }
                img(i, j, k) = sum / count;
            }
        }
    }
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

//filter 16 : Infrared Image
void infraredImage(Image& img){
    for (int i=0; i < img.width; ++i){
        for (int j=0; j < img.height; ++j){
            img(i, j, 0) = 255;
            img(i, j, 1) = 255 - img(i, j, 1);
            img(i, j, 2) = 255 - img(i, j, 2);
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
        
        cout << "\n---------------- Main Menu ----------------" << endl;
        cout << "3. Invert Colors" << endl;
        cout << "4. Add Frame" << endl;
        cout << "7. Darken / Lighten " << endl;
        cout << "8. Resize Image" << endl;
        cout << "11. Crop Image" << endl;
        cout << "12. Blur Image" << endl;
        cout << "15. Purple Tint" << endl;
        cout << "16. Infrared Image" << endl;
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

            case 4: {
                int frameType, frameColor;
                cout << "What type of frame would you like?" << endl;
                cout << "1. Simple\n2. Fancy\nYour choice: ";
                cin >> frameType;
                cout << "What color would you like for the frame?" << endl;
                cout << "1. White\n2. Blue\n3. Red\nYour choice: ";
                cin >> frameColor;
                addFrame(currentImage, frameType, frameColor);
                cout << "Frame applied successfully!" << endl;
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

            case 8: {
                int newW=0, newH=0;
                int resizeChoice;
                cout << "Choose resize method: " << endl;
                cout << "1. New dimensions (Width, Height)\n2. Ratio\nYour choice: ";
                cin >> resizeChoice;
                if (resizeChoice == 1) {
                    cout << "Enter new width: "; cin >> newW;
                    cout << "Enter new height: "; cin >> newH;
                } else if (resizeChoice == 2) {
                    float ratio;
                    cout << "Enter ratio (e.g., 0.5 for half size, 2.0 for double size): ";
                    cin >> ratio;
                    newW = currentImage.width * ratio;
                    newH = currentImage.height * ratio;
                }
                resizeImage(currentImage, newW, newH);
                cout << "Image resized successfully!" << endl;
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

            case 12: {
                int level, blurSize;
                cout << "Enter blur size:\n 1. Light\n 2. Medium\n 3. Strong\nYour choice: ";
                cin >> level;
                if (level == 1) { blurSize = 5;} 
                else if (level == 2) {blurSize = 10;} 
                else { blurSize = 15;}
                blurImage(currentImage, blurSize);
                cout << "Blur applied successfully!" << endl;
                break;
            }

            case 15: {

                purplefilter(currentImage);
                cout << "Purple filter applied successfully!" << endl;
                break;
            }

            case 16: {
                infraredImage(currentImage);
                cout << "Infrared filter applied successfully!" << endl;
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
>>>>>>> 9e933a506373265dc7991a6d31b49f70d75cc911
