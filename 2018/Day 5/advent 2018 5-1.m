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
        NSString *myPath = @"/Users/michael.herman/tmp/advent_day5.txt";
        NSString *myFile = [[NSString alloc]initWithContentsOfFile:myPath encoding:NSUTF8StringEncoding error:nil];
        //        NSSortDescriptor *sortDescriptor = [[NSSortDescriptor alloc]initWithKey:nil ascending:YES];
        //        NSArray *myArray = [myFile componentsSeparatedByString:@"\n"];
        //        myArray = [myArray sortedArrayUsingDescriptors:@[sortDescriptor]];
        
        NSMutableString *myString = [[NSMutableString alloc]initWithString:myFile];
        NSInteger i = 0;
        
        NSLog(@"Starting string count is %ld",[myString length]);
        
        while (i <[myString length]-1) {
            NSString *currentLetter = [myString substringWithRange:NSMakeRange(i, 1)];
            NSString *nextLetter = [myString substringWithRange:NSMakeRange(i+1, 1 )];
            
            if ([[NSCharacterSet lowercaseLetterCharacterSet] characterIsMember:[currentLetter characterAtIndex:0]] && [currentLetter uppercaseString] == nextLetter ) {
                [myString deleteCharactersInRange:NSMakeRange(i, 2)];
                if (i != 0) {
                    i = i -1;
                }
            } else if ([[NSCharacterSet uppercaseLetterCharacterSet] characterIsMember:[currentLetter characterAtIndex:0]] && [currentLetter lowercaseString] == nextLetter ) {
                [myString deleteCharactersInRange:NSMakeRange(i, 2)];
                if (i != 0) {
                    i = i -1;
                }
            } else {
                i++;
            }
            
        }
        NSLog(@"%@,%ld",myString,[myString length]);
        
        
        
        
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

