
// very simple , like in the computer game
/*
Leet Code 657
Judge Route Circle
Initially, there is a Robot at position (0, 0). Given a sequence of its moves, 
judge if this robot makes a circle, which means it moves back to the original place.

The move sequence is represented by a string. And each move is represent by a character.
The valid robot moves are R (Right), L (Left), U (Up) and D (down). 
The output should be true or false representing whether the robot makes a circle. 


*/

class Solution {
public:
    bool judgeCircle(string moves) {
        
        int sz=moves.size();
        int curX=0;
        int curY=0;
        
        for(int i=0; i< sz ; i++ ){
            switch(moves[i]) {
                    
                case 'U':
                    curY+=1;
                    break;
                case 'D':
                    curY-=1;
                    break;
                case 'L':
                    curX-=1;
                    break;
                case 'R':
                    curX+=1;
                    break;
                default:
                    break;
            }
        }
        
        
        if((curX==0) and (curY==0))
            return true;
        
        return false;
    }
};