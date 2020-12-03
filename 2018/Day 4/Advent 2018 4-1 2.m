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
        NSMutableDictionary *guardSummary = [[NSMutableDictionary alloc]init];
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
                NSMutableArray *tempTime = [[NSMutableArray alloc]init];
                NSNumber *guardIdObj = [NSNumber numberWithInteger:guardId];
                wakeUpMinute = parseTime([lineArray[1] substringToIndex:5]);
                NSInteger timeAsleep = wakeUpMinute - fallAsleepMinute;
                

                if ([guardSummary objectForKey:guardIdObj]) {
                    NSInteger tempSummary = [[guardSummary objectForKey:guardIdObj]integerValue];
                    NSNumber *totalSleep = [NSNumber numberWithInteger:timeAsleep+tempSummary];
                    
                    [guardSummary removeObjectForKey:guardIdObj];
                    [guardSummary setObject:totalSleep forKey:guardIdObj];
        
                } else {
                    [guardSummary setObject:[NSNumber numberWithInteger:timeAsleep] forKey:guardIdObj];
                }
                
                NSLog(@"%@",guardIdObj);
                if ([guardDetails objectForKey: guardIdObj]) {
                    for (NSInteger i = fallAsleepMinute; i<wakeUpMinute; i++) {
                        [tempTime addObject:[NSNumber numberWithInteger:i]];
                    }
                    
                    NSCountedSet *tempSet = [NSCountedSet setWithArray:tempTime];
                    currentSet = [NSCountedSet setWithSet:[guardDetails objectForKey:guardIdObj]];
                    NSEnumerator *currEnum = [currentSet objectEnumerator];
                    
                    for (NSString *minute in currEnum) {
                        NSLog(@"current set is %@, %ld",minute,[currentSet countForObject:minute]);
                    }
                    
                    [currentSet unionSet:tempSet];
                    
                    [guardDetails removeObjectForKey:guardIdObj];
                    [guardDetails setObject:currentSet forKey:guardIdObj];
                } else {
                    for (NSInteger i = fallAsleepMinute; i<wakeUpMinute; i++) {
                        [tempTime addObject:[NSNumber numberWithInteger:i]];
                    }
                    [guardDetails setObject:tempTime forKey:guardIdObj];
                }
            }
        }
        
        NSLog(@"Guard Summary %@",guardSummary);
        
        NSInteger sleepiestGuard = 0;
        NSNumber *sleepTime = [NSNumber numberWithInteger:0];
        for (NSNumber *key in guardSummary) {
            if ([guardSummary objectForKey:key] > sleepTime) {
                sleepiestGuard = [key integerValue];
                sleepTime = [guardSummary objectForKey:key];
            }
            
        }
        NSLog(@"Sleepiest guard, %ld", sleepiestGuard);
        
        NSCountedSet *sleepiestSet = [NSCountedSet setWithSet:[guardDetails objectForKey:[NSNumber numberWithInteger:sleepiestGuard]]];
        NSEnumerator *sleepyEnum = [sleepiestSet objectEnumerator];
        for (NSString *minute in sleepyEnum) {
            NSLog(@"Enumerator is %@,%ld",minute,[sleepiestSet countForObject:minute]);
        }
//
        
        
        return 0;
        
    }
    
}







//NSCountedSet *countedSet = [[NSCountedSet alloc]initWithObjects:@[@"Eezy",@"Eezy",@"Tutorials",@"Website"], nil];
//NSEnumerator *enumerator = [countedSet objectEnumerator];
//for (NSString *aValue in enumerator) {
//    NSLog(@"%@",aValue);
//}
