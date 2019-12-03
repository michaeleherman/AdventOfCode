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
        
        NSString *myPath = @"/Users/michael.herman/tmp/advent_day2.txt";
        NSString *myFile = [[NSString alloc]initWithContentsOfFile:myPath encoding:NSUTF8StringEncoding error:nil];
        
        //        NSLog(@"%@",myPath);
        
        //        NSString *myFile = @"uosnxmfkezbojfdgwvrtaqhluy";
        //        NSMutableArray *myArray = [[NSMutableArray alloc]init];
        NSArray *myArray = [myFile componentsSeparatedByString:@"\n"];
        int countOfTwos = 0;
        int countofThrees = 0;
        
        int counter = 0;
        
        for (NSString *row in myArray) {
            NSMutableArray *currentRow = [[NSMutableArray alloc]init];
            BOOL foundTwo = NO;
            BOOL foundThree = NO;
            NSLog(@"%@",row);
            for (int i = 0; i<[row length]; i++) {
                NSString *letter =[row substringWithRange:NSMakeRange(i, 1)];
                [currentRow addObject:letter];
            }
            
            for (NSString *letter in currentRow) {
                
                NSIndexSet *countofLetter = [currentRow indexesOfObjectsPassingTest:^BOOL(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                    return [obj isEqual: letter];
                }];
                
                if ([countofLetter count] == 2 && foundTwo == NO) {
                    countOfTwos += 1;
                    foundTwo = YES;
                } else if ([countofLetter count] == 3 && foundThree == NO) {
                    countofThrees += 1;
                    foundThree = YES;
                }
            }
            counter++;
            NSLog(@"%d,%d,%d",counter,countOfTwos,countofThrees);
            
        }
        NSLog(@"%d",countofThrees*countOfTwos);
        return 0;
        
    }
    
}
