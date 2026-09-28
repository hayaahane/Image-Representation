#include<iostream>
#include"Image_Class.h"
using namespace std;


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

int main(){
    string fileName ;

    cout<<"welcom to Baby Photoshop"<<endl;
    cout<< "Please enter image name to load:";
    cin>> fileName ;

    Image image(fileName);
    int choice;

    cout<<"Choose Flip type:"<< endl;
    cout<<"1.Horizontal Flip"<<endl;
    cout<<"2.Vertical Flip"<< endl;
    cout<<"your choice is:";
    cin>> choice ;

    if (choice==1){
        HorizontalFlip(image);
    }
    else if (choice==2){
        VerticalFlip(image);
    }

    string newName ;
    cout << "enter name to save the new image:" ;
    cin >> newName ;
    image.saveImage(newName);

    cout <<"image saved successfully " << endl;


}
