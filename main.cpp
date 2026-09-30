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


int main()
{
    string fileName;

    cout << "Welcome to Baby Photoshop" << endl;
    cout << "Please enter your file name: ";
    cin >> fileName;

    Image image(fileName);

    int choice = 0;

    while (choice != 4)
    {
        cout << "Choose a filter:" << endl;
        cout << "1. GrayScale" << endl;
        cout << "2. Flip" << endl;
        cout << "3. Save Image" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            GrayScale(image);
            cout << "GrayScale applied successfully!" << endl;
            break;

        case 2:
        {
            int flipChoice;

            cout << "Choose Flip type:" << endl;
            cout << "1. Horizontal Flip" << endl;
            cout << "2. Vertical Flip" << endl;

            cout << "Enter your choice: ";
            cin >> flipChoice;

            switch (flipChoice)
            {
            case 1:
                HorizontalFlip(image);
                cout << "Horizontal Flip applied successfully" << endl;
                break;

            case 2:
                VerticalFlip(image);
                cout << "Vertical Flip applied successfully" << endl;
                break;

            default:
                cout << "Invalid choice" << endl;
            }

            break;
        }

        case 3:
        {
            string newName;

            cout << "enter name to save the new image: ";
            cin >> newName;

            image.saveImage(newName);

            cout << "Image saved successfully" << endl;
            break;
        }

        case 4:
            cout << "Goodbye" << endl;
            break;

        default:
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}