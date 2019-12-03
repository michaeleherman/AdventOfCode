//
//  main.m
//  AdventOfCode
//
//  Created by Herman, Michael on 11/23/18.
//  Copyright © 2018 com.thehermans. All rights reserved.
//

#import <Foundation/Foundation.h>


int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // Log text for timing purposes
        NSLog(@"Starting now...");
        
        // Read file into an array
        NSString *myPath = @"/Users/michael.herman/tmp/advent_day6.txt";
//                NSString *myPath = @"/Users/michael.herman/tmp/day6Test.txt";
        
        NSString *myFile = [[NSString alloc]initWithContentsOfFile:myPath encoding:NSUTF8StringEncoding error:nil];
        //        NSSortDescriptor *sortDescriptor = [[NSSortDescriptor alloc]initWithKey:nil ascending:YES];
        NSArray *myArray = [myFile componentsSeparatedByString:@"\n"];
        //        myArray = [myArray sortedArrayUsingDescriptors:@[sortDescriptor]];
        
        NSMutableArray *newRegionPoints = [[NSMutableArray alloc]init];
        
        
        int sideLength = 400;
        int distance = 0;
        int totalDistance = 0;
        
        
        for (int row = 0; row<sideLength; row++) {
            for (int col = 0; col<sideLength; col++) {
                
                
                //Going to loop through each coordinate
                //Parse the row and column and calculate distance
                //Store the row, column and distance in a temp dictionary
                
                
                for (NSString *obj in myArray) {
                    NSArray *parsedCoordinates = [obj componentsSeparatedByString:@", "];
                    int objRow = [[parsedCoordinates objectAtIndex:0]intValue];
                    int objCol = [[parsedCoordinates objectAtIndex:1]intValue];
                    distance = abs(row-objRow)+abs(col-objCol);
                    totalDistance += distance;
                }
                
                
                if (totalDistance< 10000) {
                    [newRegionPoints addObject:[NSArray arrayWithObjects:[NSNumber numberWithInt:row],[NSNumber numberWithInt:col], nil]];
                }
                
                totalDistance = 0;
            }
        }
        
        NSLog(@"New points %ld",[newRegionPoints count]);

        
        return 0;
        
    }
    
}
