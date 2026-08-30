#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            int average = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3;
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            //int rounded = (int)(value + 0.5);
            int sepiaRed = (int)(.393 * originalRed + .769 * originalGreen + .189 * originalBlue+ .5);
            int sepiaGreen = (int)(.349 * originalRed + .686 * originalGreen + .168 * originalBlue+ .5);
            int sepiaBlue = (int)(.272 * originalRed + .534 * originalGreen + .131 * originalBlue+.5);

            if (sepiaRed>255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen>255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue>255)
            {
                sepiaBlue = 255;
            }
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width/2;j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            copy[i][j]=image[i][j];
        }
    }

    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            int count=0;
            int sumRed=0;
            int sumGreen=0;
            int sumBlue=0;
            for(int k=i-1;k<=i+1;k++)
            {
                for(int l=j-1;l<=j+1;l++)
                {
                    if(k<0 || k>=height || l<0 || l>= width)
                    {
                        continue;
                    }
                    sumRed += copy[k][l].rgbtRed;
                    sumBlue += copy[k][l].rgbtBlue;
                    sumGreen += copy[k][l].rgbtGreen;
                    count++;
                }
            }
            int averageRed = (int)(sumRed/(double)count+.5);
            int averageBlue = (int)(sumBlue/(double)count+.5);
            int averageGreen = (int)(sumGreen/(double)count+.5);

            image[i][j].rgbtRed=averageRed;
            image[i][j].rgbtBlue=averageBlue;
            image[i][j].rgbtGreen=averageGreen;
        }
    }
    return;
}
