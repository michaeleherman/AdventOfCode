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
        int totalOverlap = 0;
        
        int arraySize = 1001;
        int fabric[arraySize][arraySize];
        for (int i = 0; i<arraySize; i++) {
            for (int j = 0; j<arraySize; j++) {
                fabric[i][j] = 0;
            }
        }
        
        //        NSString *row = @"#1 @ 45,64: 22x22";
        
        for (NSString *row in myArray) {
            NSCharacterSet *adventset = [NSCharacterSet characterSetWithCharactersInString:@" #@,:x"];
            NSArray *rowArray = [row componentsSeparatedByCharactersInSet:adventset];
            NSInteger claimId = [[rowArray objectAtIndex:1]integerValue];
            NSInteger leftOffset = [[rowArray objectAtIndex:4]integerValue];
            NSInteger topOffset = [[rowArray objectAtIndex:5]integerValue];
            NSInteger xLength = [[rowArray objectAtIndex:7]integerValue];
            NSInteger yLength = [[rowArray objectAtIndex:8]integerValue];
            
            
            NSLog(@"%ld,%ld,%ld,%ld,%ld",claimId,leftOffset,topOffset,xLength,yLength);
            
            for (NSUInteger i = leftOffset;i<(xLength+leftOffset); i++) {
                for (NSUInteger j = topOffset;j<(yLength+topOffset);j++) {
                    fabric[i][j] += 1;
                    if (fabric[i][j] ==2) {
                        totalOverlap++;
                        NSLog(@"%ld,%lu,%lu,%d",(long)claimId,(unsigned long)i,(unsigned long)j,fabric[i][j]);
                    }
            
                }
            }
        }
        
        NSLog(@"Total overlap: %d",totalOverlap);
        
        return 0;
        
    }
    
}
