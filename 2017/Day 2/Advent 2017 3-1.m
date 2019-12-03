514.926208306//
//  main.m
//  AdventOfCode
//
//  Created by Herman, Michael on 11/23/18.
//  Copyright © 2018 com.thehermans. All rights reserved.
//

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        int location = 265149;
//        int location = 24;
//        int sideLength;
        int longestSideLength = ceil(sqrt(location));
        int totalLength = longestSideLength*longestSideLength;
        int onePosition = (longestSideLength - 1)/2+1;
        int magicX = 0;
        int magicY = 0;


        
        NSLog(@"%d,%d,%d",longestSideLength,totalLength,onePosition);
        
        int array[longestSideLength][longestSideLength];
    
        array[0][0] = 1;
        int sideLength = 1;
        int currentSide = 1;
        int currentSideCount = 1;
        int yAxis=0;
        int xAxis=0;
        int counter = 1;
        
       
        
        while ( counter <= totalLength) {
            



            NSLog(@"count, X, Y: %d,%d,%d",counter,xAxis,yAxis);
            NSLog(@"Side, SideCount, Length: %d,%d,%d",currentSide,currentSideCount,sideLength);
             array[xAxis][yAxis] = counter;
//            NSLog(@"Array value: %d",array[xAxis][yAxis]);
            
            if (counter == 1 ) {
                currentSide = 4;
            }
            
            if (currentSide == 1 && currentSideCount == 1) {
                currentSideCount += 1;
            }
            
                        if (currentSide == 1 && currentSideCount != sideLength && counter != 1) {
                            yAxis += 1;
                            currentSideCount +=1;
                        } else if (currentSide == 1 && currentSideCount == sideLength){
                            xAxis -=1;
                            currentSide +=1;
                            currentSideCount = 2;
                        } else if (currentSide == 2 && currentSideCount != sideLength) {
                            xAxis -=1;
                            currentSideCount +=1;
                        } else if (currentSide == 2 && currentSideCount == sideLength) {
                            yAxis -=1;
                            currentSide +=1;
                            currentSideCount = 2;
                        } else if (currentSide == 3 && currentSideCount != sideLength) {
                            yAxis -=1;
                            currentSideCount +=1;
                        } else if (currentSide ==3 && currentSideCount == sideLength) {
                            xAxis +=1;
                            currentSide +=1;
                            currentSideCount = 2;
                        } else if (currentSide == 4 && currentSideCount != sideLength) {
                            xAxis +=1;
                            currentSideCount +=1;
                        }
                          else if (currentSide ==4 && currentSideCount == sideLength) {
                            currentSide =1;
                            xAxis +=1;
                            sideLength +=2;
                              currentSideCount = 1;
                        }
            
            if (counter == location) {
                magicX = xAxis;
                magicY = yAxis;
            }
            
            
            counter += 1;

//        array[-1][-1] = 14;
//        array[-14][-2]= 2543;
//        NSLog(@"%d",array[-14][-2]);
//           NSLog(@"After Counter: %d,sidelength: %d,currentSide: %d, currentSidecount: %d",counter,sideLength,currentSide,currentSideCount);
            
        }
        
        NSLog(@"%d,%d - %d",magicX,magicY,array[magicX][magicY]);
    return 0;
    }
    }
