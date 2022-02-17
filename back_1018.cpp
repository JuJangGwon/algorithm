// #include <iostream>
// #include <string>

// using namespace std;

// string BW[8] = {"BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB"};
// string WB[8] = {"WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW"};
// string board[50];
// int if_BW(int x,int y)
// {
//     int sum = 0;
//     for(int i =y;i < y+8;i++)
//     {
//         for(int j = x;j<x+8;j++)
//         {
//             if(BW[i][j]==board[i][j]) sum++;
//         }
//     }
//     return sum;
// }
// int if_WB(int x,int y)
// {
//     int sum = 0;
//     for(int i =y;i < y+8;i++)
//     {
//         for(int j = x;j<x+8;j++)
//         {
//              if(WB[i][j]==board[i][j]) sum++;
//         }
//     }
//     return sum;
// }

// int main()
// {
//     int da;

//     int min = 64;
//     int num_x,num_y;

//     scanf("%d,%d",&num_x,&num_y);

//     for(int i = 0; i<num_y;i++)
//     {
//         for(int j = 0; j<num_x;j++)
//         {
//             scanf("%s",&board[j][i]);
//         }
//     }
//     for(int i = 0;i<num_y-8;i++)
//     {
//         for(int j =0; j<num_x-8;j++)
//         {
//             int temp = 0;
//             temp = board[i][j] == 'B' ? if_BW(j,i) : if_WB(j,i);
//             if(temp < min) min = temp;
//         }
//     }
//     printf("%d",min);

//     return 0;
// }