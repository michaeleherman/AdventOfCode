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
        
        
        
        NSInteger i = 0;
        
        NSString *alphabet = @"abcdefghijklmnopqrstuvwxyz";
        NSMutableDictionary *lengthDict = [[NSMutableDictionary alloc]init];
        
        
        for (NSUInteger idx = 0;idx<[alphabet length];idx++) {
            NSMutableString *myString = [[NSMutableString alloc]initWithString:myFile];
            //            NSMutableString *myString = [[NSMutableString alloc]initWithString:@"dabAcCaCBAcCcaDA"];
            //            NSLog(@"myString is: %@",myString);
            NSString *currentAlphaLetter = [alphabet substringWithRange:NSMakeRange(idx, 1)];
            myString = [[myString stringByReplacingOccurrencesOfString:currentAlphaLetter withString:@""]mutableCopy];
            //            NSLog(@"myString is: %@,%@",myString,currentAlphaLetter);
            myString = [[myString stringByReplacingOccurrencesOfString:[currentAlphaLetter uppercaseString] withString:@""]mutableCopy];
            //            NSLog(@"Current letter is %@ and myString is: %@",currentAlphaLetter,myString);
            i = 0;
            
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
            
            [lengthDict setObject:[NSNumber numberWithInteger:[myString length]] forKey:[alphabet substringWithRange:NSMakeRange(idx, 1)]];
            
        }
        
        
        NSLog(@"%@",lengthDict);
        
        
        
        
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


