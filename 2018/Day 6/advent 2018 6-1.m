//
//  main.m
//  AdventOfCode
//
//  Created by Herman, Michael on 11/23/18.
//  Copyright © 2018 com.thehermans. All rights reserved.
//

#import <Foundation/Foundation.h>

NSArray *coordinateParser(NSString *coordinates) {
    NSArray *parsedCoordinates = [coordinates componentsSeparatedByString:@", "];
    NSString *xCoordinate = [parsedCoordinates objectAtIndex:0];
    NSString *yCoordinate = [parsedCoordinates objectAtIndex:1];
    NSArray *coordinatesArray = [NSArray arrayWithObjects:xCoordinate,yCoordinate, nil];
    NSLog(@"%@,%@",xCoordinate,yCoordinate);
    return coordinatesArray;
    
}

BOOL addOrNot(NSDictionary *tmpDict) {
    for(id item in [tmpDict allValues]){
        NSArray *keys = [tmpDict allKeysForObject:item];
        if([keys count] > 1) {
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // Log text for timing purposes
        NSLog(@"Starting now...");
        
        // Read file into an array
        NSString *myPath = @"/Users/michael.herman/tmp/advent_day6.txt";
//        NSString *myPath = @"/Users/michael.herman/tmp/day6Test.txt";

        NSString *myFile = [[NSString alloc]initWithContentsOfFile:myPath encoding:NSUTF8StringEncoding error:nil];
        //        NSSortDescriptor *sortDescriptor = [[NSSortDescriptor alloc]initWithKey:nil ascending:YES];
        NSArray *myArray = [myFile componentsSeparatedByString:@"\n"];
        //        myArray = [myArray sortedArrayUsingDescriptors:@[sortDescriptor]];
        
        NSCountedSet *permStore = [[NSCountedSet alloc]init];
        NSMutableDictionary *tmpDict = [[NSMutableDictionary alloc]init];
        NSMutableSet *infinites = [[NSMutableSet alloc]init];
        
        
        int sideLength = 400;
        NSNumber *distance = [[NSNumber alloc]init];
        
        for (int row = 0; row<sideLength; row++) {
            NSLog(@"Starting object loop %d",row);
            for (int col = 0; col<sideLength; col++) {
                
                
                //Going to loop through each coordinate
                //Parse the row and column and calculate distance
                //Store the row, column and distance in a temp dictionary
                
                
                for (NSString *obj in myArray) {
                    NSArray *parsedCoordinates = [obj componentsSeparatedByString:@", "];
                    int objRow = [[parsedCoordinates objectAtIndex:0]intValue];
                    int objCol = [[parsedCoordinates objectAtIndex:1]intValue];
                    distance = [NSNumber numberWithInt:abs(row-objRow)+abs(col-objCol)];
                    [tmpDict setObject:distance forKey:obj];
                                    }
                
                //Sorting temp dictionary entries ascending by the value
                
                NSArray *sortedKeys = [tmpDict keysSortedByValueUsingComparator:^NSComparisonResult(id  _Nonnull obj1, id  _Nonnull obj2) {
                    return [obj1 compare:obj2];
                }];
             
                //If the lowest value has more than one coordinate, don't add to the totals at all
                //Otherwise add the lowest value to the NSCountedSet
                if ([tmpDict objectForKey:[sortedKeys objectAtIndex:0]] == [tmpDict objectForKey:[sortedKeys objectAtIndex:1]]) {
                    continue;
                }
                else {
                    [permStore addObject:[sortedKeys objectAtIndex:0]];
                }
                
                if (row == 0 || col == 0 || row == sideLength -1 || col == sideLength -1) {
                    [infinites addObject:[sortedKeys objectAtIndex:0]];
                }
                
                
                
            }
            
            
            NSLog(@"Ending loop...\n\n");
            
            
            
            
        }
        
        NSEnumerator *countEnum = [permStore objectEnumerator];
        for (countEnum in permStore)  {
            if (![infinites containsObject:countEnum]) {
                NSLog(@"Final permStore contents: %@, %ld",countEnum,[permStore countForObject:countEnum]);
            }
            
        }
        

        
        
        return 0;
        
    }
    
}


//BOOL isUppercase = [[NSCharacterSet uppercaseLetterCharacterSet] characterIsMember:[s characterAtIndex:0]];
//NSMutableString *string1 = [NSMutableString stringWithString: @"aaa 123 yes there aaaa even more a y a y aaa,"];
//
//[string1 replaceOccurrencesOfString:@"aaa" withString:@"" options:0 range:NSMakeRange(0, string1.length)];
//NSLog (@"string1 = %@", string1);
//}

//    NSRange lowercaseCharRange = [@"abc" rangeOfCharacterFromSet:[NSCharacterSet lowercaseLetterCharacterSet]];
//    NSLog(@"%d",lowercaseCharRange.location!=NSNotFound);
//

//[string1 replaceOccurrencesOfString:@"aaa" withString:@"" options:0 range:NSMakeRange(0, string1.length)];


//NSArray *sortedKeys = [self.platformDict  keysSortedByValueUsingComparator:^NSComparisonResult(id obj1, id obj2) {
//    return [(NSNumber*)obj2 compare:(NSNumber*)obj1];
