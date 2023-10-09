// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name:				xxxxxx.cpp
// Last Modification Date:	xx/xx/xxxx
// Author1 and ID and Group:	Alaa saeed taha        20221256    group A
// Author2 and ID and Group:	Israa mahmoud hussien  20221016        group A
// Teaching Assistant:		xxxxx xxxxx
// Purpose:..........

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE], image1[SIZE][SIZE],image2[SIZE][SIZE];

void loadImage();
void selectFilter();
void saveImage();
void bwImage();
void invertFilter();
void mergeFilter();
void flipImageO();
void DLImage();
void RotateImage();


int main()
{

    loadImage();
    selectFilter();
    saveImage();
    return 0;
}

void loadImage()
{
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add .bmp extension and load the image
    strcat(imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}

void selectFilter(){
    cout<<"Please select a filter to apply or 0 to exit:"<<endl;
    cout<<"1- Black & White Filter"<<endl;
    cout<<"2- Invert Filter"<<endl;
    cout<<"3- Merge Filter"<<endl;
    cout<<"4- Flip Image"<<endl;
    cout<<"5- Darken and Lighten Image"<<endl;
    cout<<"6- Rotate Image"<<endl;

    char n;cin>>n;
    if(n=='1'){
        bwImage();
    }
    else if(n=='2'){
        invertFilter();
    }
    else if(n=='3'){
        mergeFilter();
    }
    else if(n=='4'){
        flipImageO();
    }
    else if(n=='5'){
        DLImage();
    }
    else if(n=='6'){
        RotateImage();
    }

}


void bwImage(){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            if (image[i][j]>127) // if bites is >127 we will make them white
                image[i][j] =255;

            else   // if they don't we make them black

                image[i][j]=0;
        }
    }
}

void invertFilter(){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            // to get inverse of image =(255-number of bites for each pixel)
            image[i][j]=255-image[i][j];
        }
    }
}

void mergeFilter(){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {

            //we need to avarge the sum of two images
            image2[i][j] = (image1[i][j]+image[i][j])/2;
        }
    }
}

void flipImageO(){
    char choose;
    cout << "Flip (h)orizontally or (v)ertically ?" << endl;

    cin >> choose;

    if (choose == 'h') { // Flip horizontally
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                // Swap pixels horizontally
                unsigned char image2 = image[i][j];
                image[i][j] = image[i][SIZE - 1 - j];
                image[i][SIZE - 1 - j] = image2;
            }
        }
    } else if (choose == 'v') { // Flip vertically
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE; j++) {
                // Swap pixels vertically
                unsigned char image2 = image[i][j];
                image[i][j] = image[SIZE -1 - i][j];
                image[SIZE - 1 - i][j] = image2;
            }
        }
    }
}

void DLImage(){
    char n;
    cout<<"Do you want to (d)arken or (l)ighten?"<<endl;
    cin>>n;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            // to get a light image we will this equation((255-number of bites for each pixel)/20 ehen add them on

            if (n == 'l') {
                image[i][j] = (255 - image[i][j]) / 2 + image[i][j];

                //for a dark image (nunber of bites/2)

            } else
                image[i][j] = image[i][j] / 2;
        }
    }
}

void RotateImage()
{
    int degrees;
    cout << "Rotate (90), (180) or (270) degrees?" << endl;

    cin >> degrees;

    unsigned char rotatedImage[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            // The variable 'degrees' represents the angle at which the image should be rotated (90, 180, or 270 degrees).
            switch (degrees)
            {
                // When rotating 90 degrees clockwise:
                case 90:
                    // Calculate the new pixel position in the rotated image.
                    // The pixel at (i, j) in the original image becomes (j, SIZE - i - 1) in the rotated image.
                    rotatedImage[i][j] = image[SIZE - j - 1][i];
                    break;

                    // When rotating 180 degrees clockwise:
                case 180:
                    // Calculate the new pixel position in the rotated image.
                    // The pixel at (i, j) in the original image becomes (SIZE - i - 1, SIZE - j - 1) in the rotated image.
                    rotatedImage[i][j] = image[SIZE - i - 1][SIZE - j - 1];
                    break;

                    // When rotating 270 degrees clockwise:
                case 270:
                    // Calculate the new pixel position in the rotated image.
                    // The pixel at (i, j) in the original image becomes (j, SIZE - i - 1) in the rotated image.
                    rotatedImage[i][j] = image[j][SIZE - i - 1];
                    break;

                    // If the 'degrees' value is not 90, 180, or 270, no rotation is performed.
                default:
                    break;
            }

        }
    }
    // We copy the rotated image to the original image to preserve the rotated image to show it to the user
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = rotatedImage[i][j];
        }
    }


}

void saveImage()
{
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add .bmp extension and save the image
    strcat(imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}