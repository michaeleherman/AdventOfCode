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
        NSArray *myArray = [myFile componentsSeparatedByString:@"\n"];
        
        //        NSString *string1 = @"uosnxmfkezbojfdgwvrtaqhluy";
        //        NSCharacterSet *string2 = [NSCharacterSet characterSetWithCharactersInString:@"iosnxmfkazbcopdgnvrtaqhluy"];
        
        for (NSString *row in myArray) {
            for (NSString *otherRow in myArray) {
                int errors = 0;
                for (int i=0;i<[otherRow length];i++) {
                    NSString *curRowChar = [row substringWithRange:NSMakeRange(i, 1)];
                    NSString *curOtherChar = [otherRow substringWithRange:NSMakeRange(i, 1)];
                    if ([curRowChar isNotEqualTo:curOtherChar]) {
                        errors++;
                    }
                }
                if (errors == 1) {
                    NSLog(@"%@,%@",row,otherRow);
                }
            }
            
            
        }
        
        
        return 0;
        
    }
    
}
