#include<iostream>
#include"Image_Class.h"
using namespace std;

//GrayScale
void GrayScale(Image&image) {
    for ( int i=0 ; i < image.width ; i++){
        for (int j=0 ; j < image.height ; j++){
            unsigned int avg=0;

            for (int k=0 ; k < 3 ; k++){
                avg+= image(i,j,k);
            }
            avg /=3 ;
            image.setPixel(i,j,0,avg);
            image.setPixel(i,j,1,avg);
            image.setPixel(i,j,2,avg);
        }
    }
}

//flip
void  HorizontalFlip (Image&image) {
    for(int i=0 ; i < image.width/2 ; i++){
        for(int j=0 ; j < image.height ; j++){
            for(int k=0 ; k < 3 ; k++){
                unsigned char temp= image(i,j,k);
                image(i,j,k) = image(image.width-i-1,j,k);
                image(image.width-i-1,j,k)= temp;


            }
        }

    }

}


void VerticalFlip(Image&image){
    for(int i=0 ; i < image.width ; i++){
        for(int j=0 ; j < image.height/2 ; j++){
            for(int k=0 ; k < 3 ; k++){
                unsigned char temp = image(i,j,k);
                image(i,j,k)= image(i,image.height-j-1,k);
                image(i,image.height-j-1,k)= temp;
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