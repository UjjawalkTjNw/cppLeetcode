class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>v;
        int n = words.size(); //2
        for(int i = 0 ; i<n ;i++){
            string str = words[i]; //leet  code
            int m = str.length(); // 4  4 
            for(int j = 0 ;j < m ;j++){
                char z = str[j]; //l e e t  c o d e
                if(z == x){
                    v.push_back(i); //[0 ,0 , 1] -> [0,1]
                    break;  //this will help to exit as soon as if condition matches
                }
            }
        }
        return v;
    }
}; //O(n*m)