#include <iostream>
#include "Image_Class.h"
#include <cmath>
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



void detectedges (Image &image ) {
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
        for (int x=0; x<image.width-1; x++){
          for(int y=0; y<image.height-1; y++){
            int diff= abs(image(x,y,0)-image(x+1,y,0));
            if (diff>50){
                image.setPixel(x,y,0,0);
                image.setPixel(x,y,1,0);
                image.setPixel(x,y,2,0);}
                else{
                    image.setPixel(x,y,0,255);
                    image.setPixel(x,y,1,255);
                    image.setPixel(x,y,2,255);
                }
                
                

        
            }
        }   
}



void wanoTV (Image&image){
    for (int x=0; x<image.width; x++){
        for(int y=0; y<image.height; y++){
            if(y%4==0){
                int a=image(x,y,0);
                int b=image(x,y,1);
                int c=image(x,y,2);
                image.setPixel(x,y,0,a/2);
                image.setPixel(x,y,1,b/2);
                image.setPixel(x,y,2,c/2);

            }


        }
    }
}



void skweImage (Image&image, float skewfactor){
    double red = skewfactor*3.14/180;
    double step = tan(red);
    int newwidth = image.width + (image.height * step);
    Image newimage(newwidth, image.height);
    for (int x = 0; x < newimage.width; x++) {
        for (int y = 0; y < newimage.height; y++) {
            newimage.setPixel(x, y, 0, 255);
            newimage.setPixel(x, y, 1, 255);
            newimage.setPixel(x, y, 2, 255);
        }
    }
    for (int x = 0; x < image.width; x++) {
        for (int y = 0; y < image.height; y++) {
            int newx = x + (y * step);
            if (newx >= 0 && newx < newimage.width) {
                for (int c = 0; c < 3; c++) {
                    newimage.setPixel(newx, y, c, image(x, y, c));
                }
            }
        }
    }
    image = newimage;
}



void oilPainting (Image&image){
    int radius=5;
    int levels=15;
    Image newimage(image.width,image.height);
    for (int x=0; x<image.width; x++){
        for(int y=0; y<image.height; y++){
            int intensityCount[15]={0};
            int sumR[15]={0};
            int sumG[15]={0};
            int sumB[15]={0};
            for(int a=-radius; a<=radius; a++){
                for(int b=-radius; b<=radius; b++){
                    int newX=x+a;
                    int newY=y+b;
                    if(newX>=0 && newX<image.width && newY>=0 && newY<image.height){
                        int r=image(newX,newY,0);
                        int g=image(newX,newY,1);
                        int bl=image(newX,newY,2);
                        int intensity=(r+g+bl)/3;
                        int index=intensity*levels/256;
                        if(index>14) index=14;
                        intensityCount[index]++;
                        sumR[index]+=r;
                        sumG[index]+=g;
                        sumB[index]+=bl;
                    }
                }
            }
                        int maxindex=0;
                        int maxcount=0;
                        for(int i=0; i<levels; i++){
                            if(intensityCount[i]>maxcount){
                                maxcount=intensityCount[i];
                                maxindex=i;
                            }
                        }
                                newimage.setPixel(x,y,0,sumR[maxindex]/maxcount);
                                newimage.setPixel(x,y,1,sumG[maxindex]/maxcount);
                                newimage.setPixel(x,y,2,sumB[maxindex]/maxcount);
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
        cout << "2. blackandwite\n";
        cout << "6. rotateimage \n";
        cout << "10. detectedges \n";
        cout << "14. wanoTV \n";
        cout << "17. skweImage \n";
        cout << "18. oilpanting \n";
        cin >> choice;

        switch (choice) {

            case 2:
            blackandwhite(image);
            image.saveImage("blackandwhite_"+imagename);
                cout<< "done! BAW FILTER."<<endl;
                break;

                case 6:{
                int angle;
                 cout<< "Enter rotation angle (90, 180, 270): ";
                 cin>> angle;
                rotateimage(image,angle);
                image.saveImage("rotated_" + imagename);
                cout<< "done! imagerotate."<<endl;
                break;
                }

                case 10:
                detectedges(image);
                image.saveImage("detectedges_" + imagename);
                cout<< "done! detectedges."<<endl;
                break;

                case 14:
                   wanoTV(image);
                   image.saveImage("wanoTV_" + imagename);
                   cout<< "done! wanoTV."<<endl;
                   break;

                case 17:{
                    float angle;
                    cout<< "Enter skew angle: ";
                    cin>> angle;
                    skweImage(image,angle);
                    image.saveImage("skewed_" + imagename);
                    cout<< "done! skweImage."<<endl;
                    break;
                }

                case 18:
                    oilPainting(image);
                    image.saveImage("oilpainting_" + imagename);
                    cout<< "done! oilpainting."<<endl;
                    break;

                default:
            cout << "ERROR!" << endl;
            break;
        }  
    }
    return 0;

}
    
