//
//  main.m
//  AdventOfCode
//
//  Created by Herman, Michael on 11/23/18.
//  Copyright © 2018 com.thehermans. All rights reserved.
//

#import <Foundation/Foundation.h>

NSArray *lineParser(NSString *line) {
    NSString *firstStep = [line substringWithRange:NSMakeRange(5, 1)];
    NSString *secondStep = [line substringWithRange:NSMakeRange(36, 1)];
    return [NSArray arrayWithObjects:firstStep,secondStep, nil];
};

//NSArray *findMatches(NSString *firstStep, NSString *secondStep) {
//
//    for
//
//        };


int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // Log text for timing purposes
        NSLog(@"Starting now...");
        
        // Read file into an array
        NSString *myPath = @"/Users/michael.herman/Github/Advent of Code 2018/Day 7/day7.txt";
        //                NSString *myPath = @"/Users/michael.herman/tmp/day6Test.txt";
        
        NSString *myFile = [[NSString alloc]initWithContentsOfFile:myPath encoding:NSUTF8StringEncoding error:nil];
        NSArray *myArray = [myFile componentsSeparatedByString:@"\n"];
        
        //Project specific
        NSMutableDictionary *h = [[NSMutableDictionary alloc]init];
        
        
        
        for (NSString *line in myArray) {
            NSArray *tmpSteps = lineParser(line);
            NSString *stepI = [tmpSteps objectAtIndex:1];
            NSString *stepJ = [tmpSteps objectAtIndex:0];
            
            if (![h objectForKey:stepI]){
                [h setObject:[NSMutableArray array] forKey:stepI];
            }
            
            if (![h objectForKey:stepJ]) {
                [h setObject:[NSMutableArray array] forKey:stepJ];
            }
            
            
            
            NSMutableArray *tmpArray = [h objectForKey:stepI];
            [tmpArray addObject:stepJ];
            [h setObject:tmpArray forKey:stepI];
            
        }
        
        NSMutableArray *r = [[NSMutableArray alloc]init];
        NSArray *e = [[NSArray alloc]init];
        NSMutableArray *eTmpArray = [[NSMutableArray alloc]init];

        while ([h count] > 0) {
            for (NSString *key in h) {
                
                if ([[h objectForKey:key]count] == 0) {
                    [eTmpArray addObject:key];
                }
            }
            
            
            [eTmpArray sortUsingComparator:^NSComparisonResult(id  _Nonnull obj1, id  _Nonnull obj2) {
                //                NSLog(@"obj1 %@ obj2 %@ compare %ld",obj1,obj2,[obj1 compare: obj2]);
                return [obj1 compare: obj2];
            }];
            
            
            if ([eTmpArray count] != 0){
                e = [eTmpArray objectAtIndex:0];
                
                
                
                
                
                NSLog (@"E value is %@",e);
                [h removeObjectForKey:e];
                
                for (NSString *key in h) {
                    if ([[h objectForKey:key]containsObject:e]) {
                        [[h objectForKey:key] removeObject:e];
                    }
                }
                
                
                [r addObject:e];
                [eTmpArray removeAllObjects];
            }
            
            
            
            
        }
        
        
        
        NSLog(@"value is %@",r);
        
        return 0;
    }
    
}
