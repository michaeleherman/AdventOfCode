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
        
        NSInteger frequencyShift = 0;
        NSMutableArray *frequencyArray = [NSMutableArray array];
        // get a reference to our file
//        NSString *myPath =@"/Users/michael.herman/tmp/advent_day1.txt";
        
//        NSLog(@"%@",myPath);

        
        // read the contents into a string
//        NSString *myFile = [[NSString alloc]initWithContentsOfFile:myPath encoding:NSUTF8StringEncoding error:nil];
        NSString *myFile =@"+3, +3, +4, -2, -4";
        
        // display our file
//        NSLog(@"Our file contains this: %@", myFile);
        
        NSArray *mySplit = [myFile componentsSeparatedByString:@"\n"];
        
//        NSLog(@"%@",mySplit);
        //First iteration
        for (NSString *line in mySplit) {
            NSInteger value = [line integerValue];
            frequencyShift += value;
            NSString *frequencyShiftString = [@(frequencyShift) stringValue];
            [frequencyArray addObject:frequencyShiftString];
//            NSLog(@"line: %@, value: %ld, FrequencyShift: %ld",line,(long)value,frequencyShift);
            if([frequencyArray containsObject:frequencyShiftString]){
//                NSLog(@"%ld,%@",frequencyShift,frequencyShiftString);
//                NSLog(@"Duplicated value: %@",line);
            }

        }
        
        for (int i = 0; i<[frequencyArray count]; i++) {
            NSLog(@"%d,%@",i,frequencyArray[i]);
        }
   
        NSLog(@"%ld",frequencyShift);
//        NSLog(@"%@", frequencyArray);
        
        return 0;
    }
}

