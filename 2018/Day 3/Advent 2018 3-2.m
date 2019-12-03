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
        
        NSString *myPath = @"/Users/michael.herman/tmp/full_advent_day3.txt";
        NSString *myFile = [[NSString alloc]initWithContentsOfFile:myPath encoding:NSUTF8StringEncoding error:nil];
        NSArray *myArray = [myFile componentsSeparatedByString:@"\n"];
        NSCharacterSet *adventset = [NSCharacterSet characterSetWithCharactersInString:@" #@,:x"];
        NSArray *rowArray = [[NSArray alloc]init];
        NSInteger claimId;
        NSInteger leftOffset;
        NSInteger topOffset;
        NSInteger xLength;
        NSInteger yLength;
        NSInteger patchSize = 0;
        //        int totalOverlap = 0;
        //        NSMutableArray myPoints = [[NSMutableArray alloc]init];
        
        int arraySize = 1000;
        int fabric[arraySize][arraySize];
        for (int i = 0; i<arraySize; i++) {
            for (int j = 0; j<arraySize; j++) {
                fabric[i][j] = 0;
            }
        }
        
        //        NSString *row = @"#1 @ 45,64: 22x22";
        
        for (NSString *row in myArray) {
            rowArray = [row componentsSeparatedByCharactersInSet:adventset];
            claimId = [[rowArray objectAtIndex:1]integerValue];
            leftOffset = [[rowArray objectAtIndex:4]integerValue];
            topOffset = [[rowArray objectAtIndex:5]integerValue];
            xLength = [[rowArray objectAtIndex:7]integerValue];
            yLength = [[rowArray objectAtIndex:8]integerValue];
            
            
            NSLog(@"%ld,%ld,%ld,%ld,%ld",claimId,leftOffset,topOffset,xLength,yLength);
            
            for (NSUInteger i = leftOffset;i<(xLength+leftOffset); i++) {
                for (NSUInteger j = topOffset;j<(yLength+topOffset);j++) {
                    fabric[i][j] += 1;
                    
                }
            }
            
        }
        
        for (NSString *row in myArray) {
            patchSize = 0;
            rowArray = [row componentsSeparatedByCharactersInSet:adventset];
            claimId = [[rowArray objectAtIndex:1]integerValue];
            leftOffset = [[rowArray objectAtIndex:4]integerValue];
            topOffset = [[rowArray objectAtIndex:5]integerValue];
            xLength = [[rowArray objectAtIndex:7]integerValue];
            yLength = [[rowArray objectAtIndex:8]integerValue];
            
            for (NSUInteger i = leftOffset;i<(xLength+leftOffset); i++) {
                for (NSUInteger j = topOffset;j<(yLength+topOffset);j++) {
                    patchSize += fabric[i][j];
                    
                }
                
            }
            
            if ( patchSize == (xLength * yLength)) {
                NSLog(@"%ld,%@,%ld",(long)patchSize,rowArray,xLength*yLength);
                if ( patchSize == (xLength * yLength)) {
                    continue;
                }
            }
            
        }
        
        
        
        return 0;
        
    }
    
}
