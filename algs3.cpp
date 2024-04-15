class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //board[i][j]
        map<int, int> numMap; //store values that have been seen before. 

        //check to see if each row contains duplicates (9 rows and columns)
        int i = 0;
        int j = 0;

        while (i<9){
            vector<char> check = board[i];
            sort(check.begin(), check.end(), greater<>());
            auto it = ++check.begin();
            while (it<check.end() && *it!='.'){
                if (*it==*(it-1)){
                    return 0;
                };
                it++;
            }
            i++;
        }
        //check to see if each column contains duplicates 
        j=0;
        while (j<9){
            numMap.clear();
            i=0;
            while (i<9){
                char value = board[i][j];
                if (numMap.count(value)){
                    return 0;
                }
                if (value!='.'){
                    numMap[value]=1;
                };
                i++;
            }
            j++;
        }

        //check to see if each box contains duplicates 
        i = 1;
        vector<int> one;
        vector<int> two;
        vector<int> three;
        for (auto vectors:board){
            for (int z=0;z<3;z++){
                vectors[z]!='.' ? one.push_back(vectors[z]) : void();
                vectors[z+3]!='.' ? two.push_back(vectors[z+3]) : void();
                vectors[z+6]!='.' ? three.push_back(vectors[z+6]) : void();
            };
            set<int> s1(one.begin(), one.end());
            set<int> s2(two.begin(), two.end());
            set<int> s3(three.begin(), three.end());



            if (i%3==0){
                if (s1.size()!= one.size() || s2.size()!=two.size() || s3.size()!=three.size()){
                    cout<<"error here"<<i<<endl;
                    return 0;
                };
                one.clear();
                two.clear();
                three.clear();
            };

            i++;
        };


        return 1;
    };
};
