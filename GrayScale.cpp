#include<iostream>
#include"Image_Class.h"
using namespace std;



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


int main(){
    string filename ;
    cout << "Welcome to Baby Photoshop" << endl;
    cout << "Please enter image name to load: ";
    cin >>filename ;

    Image image(filename);
    GrayScale(image);
    cout <<"GrayScale filter applied successfully" << endl;

    string newName ;
    cout << "enter name to save the new image:" ;
    cin >> newName ;
    image.saveImage(newName);

    cout <<"image saved successfully " << endl;


 }

