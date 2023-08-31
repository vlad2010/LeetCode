/*

Leet code 221 

Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4

*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        //printMatrix(matrix);

        int szX = matrix.size();
        if(szX==0)
            return 0;
        int szY = matrix[0].size();
        if(szY==0)
            return 0;
        
        int maxSquare=0;
        for(int i=0; i < szX ;i++) {
            
            for(int j=0; j<szY;j++)
            {
               // cout << "\n ---  matrix[i][j] " << matrix[i][j] << " i:"<< i << " j:" <<j<<endl;
               if(matrix[i][j]=='1') {
                   
                    int sqSize=0; 
                    //cout << "ready to start checkSquare2 \n";
                   sqSize = checkSquare2(i,j,matrix);
                   
                    //cout << "sqSize : " << sqSize << endl;
                    if(sqSize>maxSquare)
                        maxSquare=sqSize;
               }
                

            }
            cout << endl;
            
        }

       // cout << "MaxSquare: " << maxSquare << endl;
        
        return maxSquare;
    }
    
private:
    void printMatrix(vector<vector<char>>& matrix) {
        
        for(auto &i: matrix) {
            
            for(auto &j: i)
            {
                cout << j << " ";
            }
            cout << endl;
            
        }
        
    }
    
    
    int checkSquare2(int startX, int startY, vector<vector<char>>& matrix) 
	{

        //cout << "checkSquare2 \n";

        
//        int sz = matrix.size();
        int szX = matrix.size();
        int szY = matrix[0].size();
        
        int sqSize=1;
        int finX=startX+1;
        int finY = startY+1;

        if((finX==szX) || (finY==szY)) {
            return sqSize;
        }
        
        while(checkBorders(startX, startY, finX, finY, matrix) && (sqSize<szX) && (sqSize<szY) )
        {
            sqSize++;
            finX = finX+1;
            finY = finY+1;
            
            if((finX==szX) || (finY==szY)) {
                break;
            }
        }
        
        //cout << "checkSquare2 res sqSize: " << sqSize << " for X: " << startX << " Y:" << startY << endl;
        return sqSize*sqSize;
    }
    
    bool checkBorders(int startX, int startY, int finishX, int finishY,vector<vector<char>>& matrix) 
	{

         //cout << "checkBorders startX:" << startX << " startY:" << startY << " finishX:" << finishX << " finishY:" << finishY <<endl ;

        
        for(int y=startY; y<=finishY; y++)
        {
            //cout << "borders Y finishX:" << finishX << " y:" << y << "matrix[finishX][y] :" <<  matrix[finishX][y] << endl;
            if(matrix[finishX][y]=='0') {
                //cout << "checKborders Y Return! \n";
                return false;
            }
        }
        
        for(int x=startX; x<finishX; x++)
        {
           // cout << "borders X  x:" << x <<  " finishY:" << finishY << " matrix[x][finishY]:" << matrix[x][finishY]<<  endl;

            if(matrix[x][finishY]=='0') {
                //cout << "checKborders X Return! \n";
                return false;
            }
        }

        return true;
    }
};