//
//  main.m
//  AdventOfCode
//
//  Created by Herman, Michael on 11/23/18.
//  Copyright © 2018 com.thehermans. All rights reserved.
//

#import <Foundation/Foundation.h>


NSInteger parseTime(NSString *line) {
    NSArray *words = [line componentsSeparatedByString:@":"];
    NSString *time = words[1];
    return [time integerValue];
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // Log text for timing purposes
        NSLog(@"Starting now...");
        
        // Read file into an array
        NSString *myPath = @"/Users/michael.herman/tmp/tmp_advent_day4.txt";
        NSString *myFile = [[NSString alloc]initWithContentsOfFile:myPath encoding:NSUTF8StringEncoding error:nil];
        NSSortDescriptor *sortDescriptor = [[NSSortDescriptor alloc]initWithKey:nil ascending:YES];
        NSArray *myArray = [myFile componentsSeparatedByString:@"\n"];
        myArray = [myArray sortedArrayUsingDescriptors:@[sortDescriptor]];
        
        NSMutableDictionary *guardDetails = [[NSMutableDictionary alloc]init];
        NSCountedSet *currentSet = [[NSCountedSet alloc]init];
        
        NSInteger guardId = 0;
        NSInteger fallAsleepMinute = 0;
        NSInteger wakeUpMinute = 0;
        
        for (NSString *row in myArray) {
            NSArray *lineArray = [row componentsSeparatedByString:@" "];
            if ([row containsString:@"begins shift"]) {
                guardId = [[lineArray[3] substringFromIndex:1]integerValue];
            } else if ([row containsString:@"falls asleep"]){
                fallAsleepMinute = parseTime([lineArray[1] substringToIndex:5]);
            } else if ([row containsString:@"wakes up"]) {
                NSNumber *guardIdObj = [NSNumber numberWithInteger:guardId];
                wakeUpMinute = parseTime([lineArray[1] substringToIndex:5]);
                
                
                
                
                for (NSInteger i = fallAsleepMinute; i<wakeUpMinute; i++) {
                    NSNumber *minute = [NSNumber numberWithInteger:i];
                    NSDictionary *tempDict = [NSDictionary dictionaryWithObject:minute forKey:guardIdObj];
                    [currentSet addObject:tempDict];
                    
                    
                    NSInteger tempCount = 0;
                    NSMutableDictionary *tempGuard = [[NSMutableDictionary alloc]init];
                    NSEnumerator *setEnum = [currentSet objectEnumerator];
                    for (NSDictionary *row in setEnum) {
                        if ([currentSet countForObject:row] > tempCount) {
                            tempCount = [currentSet countForObject:row];
                            [tempGuard removeAllObjects];
                            [tempGuard addEntriesFromDictionary:row];
                        }
                    }
                    NSLog(@"Temp Guard is %@",tempGuard);
                    return 0;
                    
                }
                
            }
            
