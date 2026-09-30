#include <iostream>
#include "Image_Class.h"
using namespace std;
void blackandwhite (Image& image) {
    for (int x=0; x< image.width; x++)
        for (int y=0; y< image.height; y++)
        {
           int a=image (x,y,0);
           int b=image (x,y,1);
           int c=image (x,y,2);
           int avg= (a+b+c) /3;
           int newvalue ;
           if (avg>127)
              newvalue=255;
           else
              newvalue=0;
           image.setPixel (x, y, 0, newvalue);
           image.setPixel (x, y, 1, newvalue);
           image.setPixel (x, y, 2, newvalue);
        }
}



void rotateimage (Image &image ,int angle){
    int w=image.width;
    int h=image.height;
    Image newimage(h,w);
    if (angle==90 || angle==270){
        newimage=Image(h,w);
    }
    else if (angle==180){
        newimage=Image(w,h);
    }
    for(int x=0; x<w; x++){
        for(int y=0;y<h; y++){
            int newx,newy;
            if(angle==90){
                newx=h-y-1;
                newy=x;
            }
                else if(angle==270){
                    newx=y;
                    newy=w-x-1;
                }
                    else if(angle==180){
                        newx=w-1-x;
                        newy=h-1-y;
                    }
                for(int c=0; c<3; c++){
                   newimage.setPixel(newx,newy,c,image(x,y,c)); 
                }        
            }
        }
        image=newimage;
}


int main() {
     Image image;
    string imagename;
    int choice;
    cout<< "Enter imageename: ";
    cin>> imagename;
    if (image.loadNewImage(imagename)) {
        cout << "choose a filter :\n";
        cout << "1. blackandwite\n";
        cout << "2. rotateimage \n";
        cin >> choice;
        if (choice==1){
            blackandwhite(image);
            image.saveImage("blackandwhite_"+imagename);
                cout<< "done! BAW FILTER."<<endl;
        }
                else if (choice==2){
                int angle;
                 cout<< "Enter rotation angle (90, 180, 270): ";
                 cin>> angle;
                rotateimage(image,angle);
                image.saveImage("rotated_" + imagename);
                cout<< "done! imagerotate."<<endl;
                }
               else {
            cout << "ERROR!" << endl;
        }  
    } 
    return 0;
} 
