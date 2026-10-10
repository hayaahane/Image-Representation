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
            }
        }
    }
}


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
                    
                }
            }

        }
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



