#include "helpers.h"
#include <math.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    
    float grayscalefilt;
    
    for (int i = 0; i < width; i++)
    {
        for (int k = 0; k < width; k++)
        {
            grayscalefilt = round((image[k][i].rgbtRed + image[k][i].rgbtGreen + image[k][i].rgbtBlue) / 3.000);
            
            image[k][i].rgbtRed = grayscalefilt;
            image[k][i].rgbtGreen = grayscalefilt;
            image[k][i].rgbtBlue = grayscalefilt;
        }
    }
}
    
  int maxvalue(int RGB)
  {
      if (RGB > 255)
      {
          RGB = 255;
      }
      
      return RGB;
  }
  

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed;
    int sepiaGreen;
    int sepiaBlue;
    
    for (int i = 0; i < width; i++)
    {
        for ( int k = 0; k < height; k++)
        {
            sepiaRed = maxvalue(round(0.393 * image[k][i].rgbtRed + 0.769 * image[k][i].rgbtGreen + 0.189 * image[k][i].rgbtBlue));
            sepiaGreen = maxvalue(round(0.349 * image[k][i].rgbtRed + 0.686 * image[k][i].rgbtGreen + 0.168 * image[k][i].rgbtBlue));
            sepiaBlue = maxvalue(round(0.272 * image[k][i].rgbtRed + 0.534 * image[k][i].rgbtGreen + 0.131 * image[k][i].rgbtBlue));
        
            image[k][i].rgbtRed = sepiaRed;
            image[k][i].rgbtGreen = sepiaGreen;
            image[k][i].rgbtBlue = sepiaBlue;
        }
    }    
  return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int color[3];
    
    for (int i = 0; i < width / 2; i++)
    {
        for(int k = 0; k < height; k++)
        {
            color[0] = image[k][i].rgbtRed;
            color[1] = image[k][i].rgbtGreen;
            color[2] = image[k][i].rgbtBlue;
        
            image[k][i].rgbtRed = image[k][width - i - 1].rgbtRed;
            image[k][i].rgbtGreen = image[k][width - i - 1].rgbtGreen;
            image[k][i].rgbtBlue = image[k][width - i - 1].rgbtBlue;
          
            image[k][width - i - 1].rgbtRed  = color[0];
            image[k][width - i - 1].rgbtGreen = color[1];
            image[k][width - i - 1].rgbtBlue =  color[2];
          
        }
        
    }



    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
   int TotalRed;
   int TotalGreen;
   int TotalBlue;
   float counter;
   RGBTRIPLE temporary[height][width];
   
   for (int i = 0; i < width; i++)
   {
       for (int k = 0; k < height; k++)
       {
           TotalRed = 0;
           TotalGreen = 0;
           TotalBlue = 0;
           counter = 0.00;
         
         for (int j = -1; j < 2; j++)
         {
             if (k + j < 0 || j + k > height - 1)
             {
                 continue;
             }
             for (int h = -1; h < 2; h++)
             {
                 if (i + h < 0 || i + h > width - 1)
                 {
                     continue;
                 }
             
             TotalRed += image[j + k][i + h].rgbtRed;
             TotalGreen += image[j + k][i + h].rgbtGreen;
             TotalBlue += image[j + k][i + h].rgbtBlue;
             counter++;
             }
             
         }  
           
       temporary[k][i].rgbtRed = round(TotalRed / counter);
       temporary[k][i].rgbtBlue = round(TotalBlue / counter);
       temporary[k][i].rgbtGreen = round(TotalGreen / counter);
   }
 
 }   
   for (int i = 0; i < width; i++)
   {
       for (int k = 0; k < height; k ++)
       {
           image[k][i].rgbtRed = temporary[k][i].rgbtRed;
           image[k][i].rgbtGreen = temporary[k][i].rgbtGreen;
           image[k][i].rgbtBlue = temporary[k][i].rgbtBlue;
       }
   }
   
 }
