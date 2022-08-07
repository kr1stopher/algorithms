#include<iostream>
#include<vector>

//print a string located within double quotes 
std::string myString = "\"geeksforgeeks\"";
void double_qoutes(std::string myString){
    int i = 0;
    std::vector<int> quotes;
    while (i<myString.size()-1){
        char index = myString[i];
        if (myString[i] == '\"'){
            quotes.push_back(i);
        }
    }

}

//check if a string is a panindrome or not 
bool isPalindrome (std::string myString){
    bool isPalindrome = true; 
    int length = myString.length();
    int i = 0;
    while (i<length/2){
        if (myString[i] != myString[length -1 - i]){
            isPalindrome = false;
        }
        i++;
    }
    if (isPalindrome){
        std::cout<<myString<<std::endl;
    }
    return isPalindrome;
}

//check if a subsequence is in a string 
std::vector<int> subsequence (std::string myString, std::string sequence){
    bool sequence_detected = false;
    int length = myString.length();
    int i = 0;
    std::vector<int> occurences;
    std::cout<<"starting subsequence function"<<std::endl;
    while (i<length-(sequence.length()-1)){
        std::cout<<myString[i]<<std::endl;
        if (myString[i] == sequence[0]){
            int j = 1; 
            while (j<=sequence.length()-1){
                std::cout<<myString[i+j]<<"    "<<sequence[j]<<"   i,j:"<<i<<", "<<j<<std::endl;
                if (myString[i+j] != sequence[j]){
                    break;
                }
                if (j == sequence.length()-1){
                    sequence_detected = true;
                    occurences.push_back(i);
                }
                j++;
            }
        }
        i++;
    }
    return occurences;
}



void all_palindrones(std:: string myString){
    int string_length = 0; //check all lengths
    while (string_length<myString.length()){
        int i = 0;
        while(i+string_length<=myString.length()){
            isPalindrome(myString.substr(i,string_length));
            i++;
        }
        string_length++;
    }
}







int main(){
    std::string myString = "racecar";
    std::cout<<isPalindrome(myString)<<std::endl;

    std::string string2 = "01000010";
    std::string substring = "10";
    std::vector<int> occurences = subsequence(string2, substring);
    std::cout<<"Here are the indexes of subsequence occurences:"<<std::endl;
    for (int i = 0; i<occurences.size();i++){
        std::cout<<occurences[i]<<std::endl;
    }

    //substrings 
    std::string newString = "goog";
    // std::string newString = "google";
    std::cout<<std::endl<<"palindrome substings"<<std::endl;
    // palindrome_substrings(newString);
    all_palindrones("google");
    return 0;
}