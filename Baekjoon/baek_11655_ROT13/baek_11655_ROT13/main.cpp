//
//  main.cpp
//  baek_11655_ROT13
//
//  Created by 윤정인 on 2018. 7. 12..
//  Copyright © 2018년 윤정인. All rights reserved.
//

#include <iostream>
#include <string>
#include <ctype.h>
int main(int argc, const char * argv[]) {
    // insert code here...
    std::string input, output;
    //std::cin.ignore();
    std::getline(std::cin, input, '\n');
    //std::cout << input;
    output=input;
    
    for (int i=0; i<input.size(); ++i){
        if (!std::isalpha(input[i]))
            output[i]=input[i];
        else {
            if (input[i]<='M')
                output[i]= (char) ( input[i] + 13 ) ;
            else if ('M'<input[i] && input[i]<='Z')
                output[i]= 'A' + input[i] - 'M' - 1;
            else if (input[i]<='m')
                output[i]=(char) ( input[i] + 13 );
            else
                output[i]='a'+ ( input[i] - 'm' - 1);
        }
    }
    
    std::cout << output;
    return 0;
}
