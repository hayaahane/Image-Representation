#include<iostream>
#include"Image_Class.h"
using namespace std;

//GrayScale
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

//flip
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


//Merge

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
    



int main()
{
    string fileName;

    cout << "Welcome to Baby Photoshop" << endl;
    cout << "Please enter your file name: ";
    cin >> fileName;

    Image image(fileName);

    int choice = 0;

    while (choice != 5)
    {
        cout << "Choose a filter:" << endl;
        cout << "1. GrayScale" << endl;
        cout << "2. Flip" << endl;
        cout << "3. Merge" << endl;
        cout << "4. Save Image" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            GrayScale(image);
            cout << "GrayScale applied successfully!" << endl;
        }

        else if (choice == 2)
        {
            int flipChoice;

            cout << "Choose Flip type:" << endl;
            cout << "1. Horizontal Flip" << endl;
            cout << "2. Vertical Flip" << endl;

            cout << "Enter your choice: ";
            cin >> flipChoice;

            if (flipChoice == 1)
            {
                HorizontalFlip(image);
                cout << "Horizontal Flip applied successfully" << endl;
            }

            else if (flipChoice == 2)
            {
                VerticalFlip(image);
                cout << "Vertical Flip applied successfully" << endl;
            }

            else
            {
                cout << "Invalid choice" << endl;
            }
        }

        else if (choice == 3)
        {
            string fileName2;

            cout << "Please enter the second image name: ";
            cin >> fileName2;

            Image image2(fileName2);

            int mergeMethod = 0;

            if (image.width != image2.width || image.height != image2.height)
            {
                cout << "Choose Merge type:" << endl;
                cout << "1. Common Area" << endl;
                cout << "2. Resize" << endl;

                cout << "Enter your choice: ";
                cin >> mergeMethod;
            }

            image = Merge(image, image2, mergeMethod);

            cout << "Images merged successfully!" << endl;
        }

        else if (choice == 4)
        {
            string newName;

            cout << "Enter name to save the new image: ";
            cin >> newName;

            image.saveImage(newName);

            cout << "Image saved successfully" << endl;
        }

        else if (choice == 5)
        {
            cout << "Goodbye" << endl;
        }

        else
        {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}

