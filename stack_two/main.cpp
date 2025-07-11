/**************************************************************
Name: Eugenio Hernandez-Ocampo
Assignment: Assignment5Stacks
Purpose: implement a stack data structure that is 
         capable of handling dynamic sizes, ranging 
         from 2 to any number based on a command-line parameter
***************************************************************/
#include "main.h"

int main(int argc, char **argv) {
    /* ***************************************************************
    Main function to test the stack implementation.
  
    @param (int) (char) : n umber of command-line arguments and string
    @return (int) : exit status 
    @exceptio na : na
    * ****************************************************************/
    srand(time(NULL));

    bool validInput = true;

    if(argc != 2){
        std::cout << "\nError: Must pass only one parameter." << std::endl;
        validInput = false;
    }

    if(!check_if_num(argv[1])){
        std::cout << "\nError: Must enter a number." << std::endl;
        validInput = false;
    }

    if(validInput){
        int stackSize = std::atoi(argv[1]);

        Stack stack(&stackSize);

        Data temp;

        //testing for invalid number ID and Information
        std::cout << "\n*INVALID NUMBER AND STRING*" << std::endl;

        std::string strtemp = "";
        int tempint = -1;

        for(int i = 0; i < stackSize * MULTIPLIER; i++){
            if(stack.push(tempint, strtemp)){
                std::cout << "Pushed ID: " << tempint << ", Pushed Information: " << strtemp << std::endl;
            }
            else{
                std::cout << "Invalid ID, invalid information, or stack is full, cannot push." << std::endl;
            }
        }

        //tesing for underflow
        std::cout << "\n*UNDERFLOW*" << std::endl;

        tempint = 10;
        strtemp = "hello";

        for(int i = 0; i < stackSize * MULTIPLIER; i++){
            if(stack.isEmpty()){
                std::cout << "STACK IS EMPTY" << std::endl;
            }
            else{
                std::cout << "STACK IS NOT EMPTY" << std::endl;
            }

            if(stack.pop(temp)){
                std::cout << "Popped ID: " << temp.id << " and Information: " << temp.information << std::endl;
            }
            else{
                std::cout << "Stack is empty, cannot pop." << std::endl;
            }

            if(stack.peek(temp)){
                std::cout << "Peeking... ID: " << temp.id << ", Information: " << temp.information << std::endl;
            }
            else{
                std::cout << "Stack is empty, cannot peek." << std::endl;
            }

            if(stack.push(tempint, strtemp)){
                std::cout << "Pushed ID: " << tempint << ", Pushed Information: " << strtemp << std::endl;
            }
            else{
                std::cout << "Invalid ID, invalid information, or stack is full, cannot push." << std::endl;
            }

            if(stack.pop(temp)){
                std::cout << "Popped ID: " << temp.id << " and Information: " << temp.information << std::endl;
            }
            else{
                std::cout << "Stack is empty, cannot pop." << std::endl;
            }
        }

        //testing for neither underflow or overflow
        std::cout << "\n*NEITHER*" << std::endl;

        tempint = 5;
        strtemp = "hi";

        stack.push(tempint, strtemp);

        for(int i = 0; i < stackSize * MULTIPLIER; i++){
            tempint = rand() % 100;
            rand_string(&strtemp);

            if(stack.isEmpty()){
                std::cout << "STACK IS EMPTY" << std::endl;
            }
            else{
                std::cout << "STACK IS NOT EMPTY" << std::endl;
            }

            if(stack.push(tempint, strtemp)){
                std::cout << "Pushed ID: " << tempint << ", Pushed Information: " << strtemp << std::endl;
            }
            else{
                std::cout << "Invalid ID, invalid information, or stack is full, cannot push." << std::endl;
            }

            if(stack.peek(temp)){
                std::cout << "Peeking... ID: " << temp.id << ", Information: " << temp.information << std::endl;
            }
            else{
                std::cout << "Stack is empty, cannot peek." << std::endl;
            }

            if(stack.pop(temp)){
                std::cout << "Popped ID: " << temp.id << " and Information: " << temp.information << std::endl;
            }
            else{
                std::cout << "Stack is empty, cannot pop." << std::endl;
            }
        }

        //testing for overflow
        std::cout << "\n*OVERFLOW*" << std::endl;

        for(int i = 0; i < stackSize; i++){
            tempint = rand() % 100;
            rand_string(&strtemp);
            stack.push(tempint, strtemp);
        }

        for(int i = 0; i < stackSize * MULTIPLIER; i++){
            tempint = rand() % 100;
            rand_string(&strtemp);
            
            if(stack.isEmpty()){
                std::cout << "STACK IS EMPTY" << std::endl;
            }
            else{
                std::cout << "STACK IS NOT EMPTY" << std::endl;
            }

            if(stack.peek(temp)){
                std::cout << "Peeking... ID: " << temp.id << ", Information: " << temp.information << std::endl;
            }
            else{
                std::cout << "Stack is empty, cannot peek." << std::endl;
            }

            if(stack.push(tempint, strtemp)){
                std::cout << "Pushed ID: " << tempint << ", Pushed Information: " << strtemp << std::endl;
            }
            else{
                std::cout << "Invalid ID, invalid information, or stack is full, cannot push." << std::endl;
            }

            if(stack.pop(temp)){
                std::cout << "Popped ID: " << temp.id << " and Information: " << temp.information << std::endl;
            }
            else{
                std::cout << "Stack is empty, cannot pop." << std::endl;
            }

            if(stack.push(tempint, strtemp)){
                std::cout << "Pushed ID: " << tempint << ", Pushed Information: " << strtemp << std::endl;
            }
            else{
                std::cout << "Invalid ID, invalid information, or stack is full, cannot push." << std::endl;
            }
        }

        //testing for random operations
        std::cout << "\n*RANDOM OPERATIONS*" << std::endl;

        for(int i = 0; i < stackSize * MULTIPLIER; i++){
            int choice = rand() % 4;
            tempint = rand() % 100;
            rand_string(&strtemp);

            switch(choice){
                case 0:
                    if(stack.isEmpty()){
                        std::cout << "STACK IS EMPTY" << std::endl;
                    }
                    else{
                        std::cout << "STACK IS NOT EMPTY" << std::endl;
                    }
                    break;
                case 1:
                    if(stack.peek(temp)){
                        std::cout << "Peeking... ID: " << temp.id << ", Information: " << temp.information << std::endl;
                    }
                    else{
                        std::cout << "Stack is empty, cannot peek." << std::endl;
                    }
                    break;
                case 2:
                    if(stack.push(tempint, strtemp)){
                        std::cout << "Pushed ID: " << tempint << ", Pushed Information: " << strtemp << std::endl;
                    }
                    else{
                        std::cout << "Invalid ID, invalid information, or stack is full, cannot push." << std::endl;
                    }
                    break;
                case 3:
                    if(stack.pop(temp)){
                        std::cout << "Popped ID: " << temp.id << " and Information: " << temp.information << std::endl;
                    }
                    else{
                        std::cout << "Stack is empty, cannot pop." << std::endl; 
                    }
                    break;
            }
        }
    }

    return 0;
}