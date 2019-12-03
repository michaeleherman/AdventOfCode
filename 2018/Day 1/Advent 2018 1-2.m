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
        NSString *frequencyShiftString = [[NSString alloc] init];
        int looper = 0;
        int incrementer = 0;
        // get a reference to our file
        NSString *myPath =@"/Users/michael.herman/tmp/advent_day1.txt";
        
//        NSLog(@"%@",myPath);

        
        // read the contents into a string
        NSString *myFile = [[NSString alloc]initWithContentsOfFile:myPath encoding:NSUTF8StringEncoding error:nil];
//        NSString *myFile =@"+3, +3, +4, -2, -4";
        
        // display our file
//        NSLog(@"Our file contains this: %@", myFile);
        
        NSArray *mySplit = [myFile componentsSeparatedByString:@"\n"];
//        NSLog(@"%d",(long)[mySplit count]);

        while (looper == 0) {
//                NSLog(@"Before if, Found frequency: %d",[frequencyArray containsObject:frequencyShiftString]);
            for (int i=0; i<[mySplit count]; i++) {

                frequencyShift += [mySplit[i] integerValue];
                frequencyShiftString = [@(frequencyShift) stringValue];
                NSLog(@"%d,%@, %d,%ld,%d",i,mySplit[i],incrementer,(long)frequencyShift,[frequencyArray containsObject:frequencyShiftString]);
//                NSLog(@"%@",frequencyShiftString);


                if (incrementer>0 && [frequencyArray containsObject:frequencyShiftString]) {
                    NSLog(@"Found the dup %d,%@,%@",i,mySplit[i],frequencyShiftString);
////                    NSLog(@"Found frequency: %d",[frequencyArray containsObject:frequencyShiftString]);
                    looper++;
                    break;
                }
                   [frequencyArray addObject:frequencyShiftString];
            }

//            NSLog(@"%@",frequencyArray);

            incrementer++;
//            if (incrementer ==2) {
//                looper++;
//            };
        }


        
        return 0;
    }
}

